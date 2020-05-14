#ifndef EDGE_H
#define EDGE_H
#include<iostream>
#include<cmath>
using std::endl;
using std::cout;


class Point
{
	friend class Edge;
public:
	Point(double x=0, double y=0);
	Point(const Point& a)
	{
		x_ = a.x_;
		y_ = a.y_;
	}
	double getx() { return x_; }
	double gety() { return y_; }
 virtual void print();
private:
	double x_;
	double y_;
};
inline Point::Point(double x,double y):x_(x),y_(y)
{
}
inline void Point::print()
{
	cout << "坐标:" << "("<<x_ <<","<<y_<<")"<< endl;
}
class Edge:public Point
{
public:
	Edge(Point& a, Point& b);
	double Length();
	void print();
private:
	Point A, B;
	double length_;
};

inline Edge::Edge(Point& a, Point& b):A(a),B(b),length_(0)
{
}
inline double Edge::Length()
{
	length_ = sqrt((A.x_-B.x_)* (A.x_ - B.x_)+ (A.y_ - B.y_)* (A.y_ - B.y_));
	return length_;
}
inline void Edge::print()
{
	cout <<"长度："<< length_ << endl;
	cout << "点一";
	A.print();
	cout << "点二" ;
	B.print();
}
#endif