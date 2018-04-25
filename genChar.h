// This file contains all functions used to generate chars

#include <Magick++.h>
#include <iostream>

//used to represent different pixels in a picture
char char_array[] = " .:-=+*#%@";

// used to generate char to terminal
// PRE: 
//	image object from magick
//	number of chars per row	
void generateChar(Image &image, unsigned int col_num);

// calculate the average r/g/b value of a squre of pixels with up-left corner being (x,y) and 
// the with being sqr_width
// PRE:
//	tunnel: should be one of 'r', 'g' or 'b';
//	image: image from magick++
//  sqr_width: width of the squre of pixels
//	x, y: coordinate (x, y). Where (0, 0) is the most up-left pixel and (cols, rows) is the 
//		most down-right pixel
unsigned int getAvgRGB(char tunnel, Image &image, unsigned int sqr_width, 
	unsigned int x, unsigned int y);

// calculate the grayscale of a pixel according to its rgb values
// the grayscale value is calculated using different weghts for r/g/b
// with r: 0.3
//		g: 0.59
//		b: 0.11
unsigned int getGrayscale(unsigned int r, unsigned int g, unsigned int b);

// get the corresponding characters from giving graysacle
char getChar(unsigned int range, unsigned int grayscale);