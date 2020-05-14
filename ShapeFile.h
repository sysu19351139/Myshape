#ifndef SHAPEFILE_H
#define SHAPEFILE_H
#include<iostream>
#include"Shape.h"
#include<fstream>
#include<vector>
using namespace std;

class ShapeFile
{public:
	ShapeFile(std::ifstream&);
	void Generate();
    void print();
private:
	vector<Shape*>shapes_;
	vector<Shape*>compositeShapes_;
};
#endif