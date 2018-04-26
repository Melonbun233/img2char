/* 
	This is a small program that can display an img using characters.
	Arthor: Zhuohang Zeng
	Date: 2018-4-24
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "genChar.h"
using namespace std;
using namespace cv;

int SPECWIDTH;	//whether invert image color
int INVERSE;	//specify the output width

void invalid_arg(){
	cout << "Invalid argument" << endl;
	cout << "usage: ./img2char <filename> (<width>) (I)" << endl;
}

int main(int argc, char **argv){
	INVERSE = 0;	
	SPECWIDTH = 0;	
	int width = 0;

	if (argc == 1 || argc > 4){
		invalid_arg();
		return -1;
	}

	string filename = argv[1];

	switch (argc){
		case 3: {
			if(strcmp(argv[2], "I") == 0)
				INVERSE = 1;
			else {
				SPECWIDTH = 1;
				width = strtol(argv[2], NULL, 10);
			}
			break;
		}
		case 4: {
			if(strcmp(argv[3], "I") == 0){
				INVERSE = 1;
				SPECWIDTH = 1;
				width = strtol(argv[2], NULL, 10);
			} else {
				invalid_arg();
			}

		}
	}

	//Read img file
	Mat image;
	//we only use gray scale to for corresponding char
	image = imread(filename, IMREAD_GRAYSCALE);	
	if (image.empty()){
		cout << "Cannot open or find the image" << endl;
		return -1;
	}
	CV_Assert(image.depth() == CV_8U);

	if (SPECWIDTH == 1 && width > image.cols) //width too large
		width = image.cols;
	if (SPECWIDTH == 0)
		width = image.cols;
	cout << "Start converting image with size ";
	cout << image.cols << " x " << image.rows << endl;
	cout << "with " << width << " characters per row" << endl;
	if (INVERSE)
		cout << "color inversed" << endl;


	//get the file name
	string out_filename;
	size_t found = filename.find(".");
	if(found != string::npos){
		out_filename = filename.substr(0, found);
	} else {
		out_filename = "output";
	}

	if(INVERSE)
		out_filename += "-inversed";

	out_filename += ".html";

	generateChar(image, width, out_filename);

	return 0;
}

