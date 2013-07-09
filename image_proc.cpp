#include "image_proc.h"


/* Img_Processor constructor
 * img)dir is the directory that the image is stored at
 */
Img_Processor::Img_Processor(char * img_dir) {

    img = cvLoadImage(img_dir, CV_LOAD_IMAGE_COLOR);

    if (!img) {
        // TODO print error message stating could not open image
    }

    //smooth image using gaussian kernal
    img = cvCloneImage(img);
    cvSmooth(img, img, CV_GAUSSIAN, 3, 3);

    //change image to HSV color format
    lplimage * imgHSV = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 3);
    cvCvtColor(img, imgHSV, CV_BGR2HSV);

}
