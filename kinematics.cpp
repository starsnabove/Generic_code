//kinematics.cpp - a library for performing forward and inverse kinematics


#include "kinematics.h"

/*The kinematics class constructor
 * paramaters is an array of the DH parameters for each joint as an array
 */
Kinematcis::Kinematics(int dof_in, double ** paramaters) {

    dof = dof_in;
    params = parameters;

    for (int i = 0; i < dof; ++i) {

        DH_matrices.push_back(Matrix(4, 4));
    }

}

/* Performs forward kinematics and stores the tool tip location into position.
 * position must be an array of length 3. angles must be of length dof
 */
void Kinematics::forward(double * angles, double * position) {

    for (int i = 0; i < dof; ++i ) {

        DH_matrices[i][0][0] = cos(angles[i]);
        DH_matrices[i][0][1] = -sin(angles[i]) * cos(params[i][ALPHA]);
        DH_matrices[i][0][2] = sin(angles[i]) * sin(params[i][ALPHA]);
        DH_matrices[i][0][3] = params[i][A] * cos(angles[i]);

        DH_matrices[i][1][0] = sin(angles[i]);
        DH_matrices[i][1][1] = cos(anlges[i]) * cos(params[i][ALPHA]);
        DH_matrices[i][1][2] = -cos(angles[i]) * sin(params[i][ALPHA]);
        DH_matrices[i][1][3] = params[i][A] * sin(angles[i]);

        DH_matrices[i][2][0] = 0;
        DH_matrices[i][2][1] = sin(params[i][ALPHA]);
        DH_matrices[i][2][2] = cos(params[i][ALPHA]);
        DH_matrices[i][2][3] = params[i][D];

        DH_matrices[i][3][0] = 0;
        DH_matrices[i][3][1] = 0;
        DH_matrices[i][3][2] = 0;
        DH_matrices[i][3][3] = 1;

    }

    Matrix res = DH_matrices[0] * DH_matrices[1];
    res *= DH_matrices[2];
    res *= DH_matrices[3];

    position = {res[0][3], res[1][3], res [2][3]};
}
