#include "genChar.h"

void generateChar(Image &image, unsigned int col_num){
	if(width == 0)
		return;
	// we will devide the picture into many small squres
	unsigned int sqr_width = image.columns/width;
	unsigned int row_num = image.rows/sqr_width;
	if (row_num == 0) //number of row pixels is too small
		return;

	for (unsigned int rows = 0; rows < image.rows; rows += sqr_width){
		for (unsigned int cols = 0; cols < image.columns; cols += sqr_width){
			unsigned int r_avg = getAvg('r', image, sqr_width, cols, rows);
			unsigned int g_avg = getAvg('g', image, sqr_width, cols, rows);
			unsigned int b_avg = getAvg('b', image, sqr_width, cols, rows);
			unsigned int grayscale = getGrayscale(r_avg, g_avg, b_avg);
			cout << getChar(QuantumRange, grayscale);
		}
		cout << endl;
	}
}

unsigned int getAvg(char tunnel, Image &image, unsigned int sqr_width,
	unsigned int x, unsigned int y){
	Quantum *pixels = image.getPixels(x, y, x + sqr_width, y + sqr_width);
	sum = 0;
	if(tunnel == 'r'){
		for (int i = 0; i < sqr_width * sqr_width; i ++)
			sum += *(pixels + i).red;
	} else if (tunnel == 'g'){
		for (int i = 0; i < sqr_width * sqr_width; i ++)
			sum += *(pixels + i).green;
	} else {
		for (int i = 0; i < sqr_width * sqr_width; i ++)
			sum += *(pixels + i).blue;
	}

	return sum/(sqr_width * sqr_width);
}

unsigned int getGrayscale(unsigned int r, unsigned int g, unsigned int b){
	return r * 0.3 + g * 0.59 + b * 0.11;
}

char getChar(unsigned int range, unsigned int grayscale){
	unsigned int arr_len = sizeof(char_array)/sizeof(*char_array);
	return char_array[(grayscale/range)*arr_len];
}