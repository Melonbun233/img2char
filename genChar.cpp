#include "genChar.h"

void generateChar(Mat &image,int col_num, string out_filename){
	ofstream output;
	output.open(out_filename);

	constructHtmlHeader(output, out_filename);
	//initialize a look up table for chars
	uchar lut[256];
	for (int i = 0; i < 10; i ++){
		for (int j = 0; j < 26; j ++){
			if(26 * i + j > 255)
				break;
			lut[26 * i + j] = chars[i];
		}
	}

	// used to represent different pixels in a picture
	if(col_num == 0)
		return;
	// we will devide the picture into many small squres
	int sqr_width = image.cols/col_num;
	int row_num = image.rows/sqr_width; //row's number
	if (row_num == 0) //number of row pixels is too small
		return;

	for (int rows = 0; rows < image.rows; rows += sqr_width){
		for (int cols = 0; cols < image.cols; cols += sqr_width){
			uchar avg = getAvgGray(image, sqr_width, cols, rows);
			//cout << lut[avg];
			output << lut[avg];
		}
		//cout << endl;
		output << "\n";
	}

	constructHtmlFooter(output);
	output.close();
}

uchar getAvgGray(Mat &image, int sqr_width, int x, int y){
	int sum = 0;
	for (int rows = y; rows < sqr_width + y; rows ++){
		uchar *rows_ptr = image.ptr(rows, x);
		for (int cols = 0; cols < sqr_width; cols ++){
			sum += rows_ptr[cols];
		}
	}

	return (uchar)sum/(sqr_width * sqr_width);
}

void constructHtmlHeader(ofstream &output, string out_filename){
	output << "<!DOCTYPE html>\n";
	output << "<html>\n<head>\n<meta charset=\"UTF-8\">\n";
	output << "<title>" << out_filename << "</title>\n</head>\n";
	if(INVERSE)
		output << "<body style=\"background-color:#000000; color:#ffffff; ";
	else 
		output << "<body style=\"";
	output << "font-family:monospace; ";
	output << "line-height:3px; ";
	output << "font-size:" << FONT_SIZE << "pt\">\n";
	output << "<pre>\n";
}

void constructHtmlFooter(ofstream &output){
	output << "</pre>\n";
	output << "</body>\n";
	output << "</html>";
}