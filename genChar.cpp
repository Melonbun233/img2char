#include "genChar.h"

void generateChar(Mat &image, string out_filename){
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
	if(image.cols == 0 || image.rows == 0)
		return;

	for (int rows = 0; rows < image.rows; rows ++){
		uchar *row_ptr = image.ptr(rows, 0);
		for (int cols = 0; cols < image.cols; cols ++){
			output << lut[row_ptr[cols]];
		}
		output << "\n";
	}

	constructHtmlFooter(output);
	output.close();
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