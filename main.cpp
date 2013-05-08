/* 
 * File:   main.cpp
 * Author: pocketlabs
 *
 * Created on May 7, 2013, 7:08 PM
 */

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cstdlib>
#include <iostream>

using namespace cv;
using namespace std;

double alpha; /**< Simple contrast control */
int beta; /**< Simple brightness control */

int main(int argc, char** argv) {
    string sourceImage = "lena.jpg";
    Mat image = imread(sourceImage);
    Mat new_image = Mat::zeros(image.size(), image.type());

    /// Initialize values
    cout << " Basic Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    cout << "* Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
    cout << "* Enter the beta value [0-100]: ";
    cin >> beta;

    /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < 3; c++) {
                new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
            }
        }
    }

    /// Create Windows
    namedWindow("Original Image", 1);
    namedWindow("New Image", 1);

    /// Show stuff
    imshow("Original Image", image);
    imshow("New Image", new_image);

    /// Wait until user press some key
    waitKey();
    return 0;
}
