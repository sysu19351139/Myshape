#include<iostream>
#include"Shape.h"
#include<vector>
#include<fstream>
#include"ShapeFile.h"
using namespace std;
int main(int argc, char** argv)
{
    ifstream infile;
	if (argc == 2)
	infile.open(argv[1]);
	if (!infile) {
	cerr << "No input file!" << endl;
	return -1;
		}
	ShapeFile sfile(infile);    
	sfile.Generate();
	sfile.print();
}