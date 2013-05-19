// kinematics.h

#ifndef __KINEMATICS_H_INCLUDED__
#define __KINEMATICS_H_INCLUDED__

#include "matrix.h"
#include <math.h>

#define ALPHA 0
#define A 1
#define D 2

class Kinematics {

    private:
        int dof; // no of degrees of freedom
        vector<Matrix>DH_matrices;
        double ** params; // the DH parameters

    public:

        Kinematics(int);
        void forward(double *, double *);

};


#endif
