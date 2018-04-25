/* 
	This is a small program that can display an img using characters.
	Arthor: Zhuohang Zeng
	Date: 2018-4-24
*/

#include <Magick++.h>
#include <iostream>
#include <string>
#include <stdlib>

using namespace std;
using namespace Magick;

int main(int argc, char **argv){
	int inverse = 0;
	int specwidth = 0;
	if (argc == 1){
		cout << "Please enter file name" << endl;
		cout << "Use cmd : ./main <filename> <width>" << endl;
		return 0;
	}

	if (argc > 3){
		cout << "Invalid argument" << endl;
		cout << "Use cmd : ./main <filename> <width>" << endl;
		return 0;
	}

	string filename = argv[1];
	unsigned int width = 0;
	if (argc == 3){
		width = strtol(argc[2]);
		specwidth = 1;
	}
	InitializeMagick(*argv);

	try{
		//Read img file
		Image image;
		image.read(filename);
		if (specwidth == 1 && width > image.columns) //width too large
			width = imgae.colums;
		if (specwidth == 0)
			width = image.colums;
		generateChar(image, width);

	} catch(Exception &error_){
		cout << "Cought exception: " << error_.what() << endl;
		return 1;
	}

}