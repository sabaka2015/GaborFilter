/*
 * The program take a Gabor filter to an image

 */
#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;

const int size_slider_max = 30;
int size_slider;

const int sigma_max = 4;
int sigma;

const int theta_max = 360;
int theta;

const int lambd_max = 100;
int lambd;

const int gamm_max = 100;
int gamm;

const int psi_max = 100;
int psi;

Mat image, image_in_float, dest, dest2;

void on_trackbar( int, void* )
{
 double kernel_size = 2* (double) size_slider +1;
 
 Mat kernel = getGaborKernel(Size(kernel_size,kernel_size), sigma, theta, lambd, gamm/gamm_max, psi);
 filter2D(image_in_float, dest, image_in_float.depth(), kernel);
 dest.convertTo(dest2, CV_8U, 1.0/255, 0);
    
 //addWeighted( src1, alpha, src2, beta, 0.0, dst);

 imshow("source image", image);
 imshow( "after Gabor filter", dest2);
}

int main()
{
    //Mat image=imread("oko.jpg");
    //Mat image_in_float, dest, dest2;
    
    image=imread("oko.jpg");
    
    image.convertTo(image_in_float, CV_32F);
    
    size_slider = 21;
    
    //Gabor kernel parameters
    //int kernel_size = 21;
    //double sig = 1, th = 0, lm = 1.0, gm = 0.02, ps = 0;
    //Mat kernel = getGaborKernel(Size(kernel_size,kernel_size), sig, th, lm, gm, ps);
    
    //filter2D(image_in_float, dest, image_in_float.depth(), kernel);
    //dest.convertTo(dest2, CV_8U, 1.0/255, 0);
    
    namedWindow("source image", WINDOW_AUTOSIZE);
    namedWindow("after Gabor filter", WINDOW_AUTOSIZE); 

    char TrackbarName[50]="kernel size (2n+1)";
    createTrackbar( TrackbarName, "after Gabor filter", &size_slider, size_slider_max, on_trackbar );
    
    char TrackbarName2[50]="sigma";
    createTrackbar( TrackbarName2, "after Gabor filter", &sigma, sigma_max, on_trackbar );
    
    char TrackbarName3[50]="theta";
    createTrackbar( TrackbarName3, "after Gabor filter", &theta, theta_max, on_trackbar );
    
    char TrackbarName4[50]="lambda";
    createTrackbar( TrackbarName4, "after Gabor filter", &lambd, lambd_max, on_trackbar );
    
    char TrackbarName5[50]="gamma";
    createTrackbar( TrackbarName5, "after Gabor filter", &gamm, gamm_max, on_trackbar );
    
    char TrackbarName6[50]="psi";
    createTrackbar( TrackbarName6, "after Gabor filter", &psi, psi_max, on_trackbar );
    
    on_trackbar( size_slider, 0 );
    
    waitKey(0);
    return 0;
    /*
    while (true)
    {
        imshow("source image", image);
        imshow("after Gabor filter", dest2);
        int end = waitKey(0);
        if (end=='q') break;
    }
    return 0;
    */
}