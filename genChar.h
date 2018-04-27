// This file contains all functions used to generate chars
#ifndef GENCHAR_H
#define GENCHAR_H

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <fstream>

using namespace cv;
using namespace std;

extern int INVERSE;
//char array used to represent pixels
const char chars[] = "@%#*+=-:. ";
const int FONT_SIZE = 4;

// used to generate char to terminal
// PRE: 
//	Mat image from opencv, this should be non-empty
//	number of chars per row, this may be changed if the width is too large
void generateChar(Mat &image, string out_filename);

//construct header and tags for the output html file
void constructHtmlHeader(ofstream &output, string out_filename);

//construct footer and tags for the output html file
void constructHtmlFooter(ofstream &output);

#endif 