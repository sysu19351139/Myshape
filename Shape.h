#ifndef SHAPE_H
#define SHAPE_H
#include"Edge.h"
#include<vector>
#include <sstream>
#include<memory>
class And;
class Or;
class Shape
{
	friend class Circle;
	friend class Polygon;
	friend And operator&(Shape&s1,Shape&s2);
	friend  Or operator|(Shape&s1,Shape&s2);
public:
	virtual ~Shape()
	{};
	virtual double Area()=0;
	virtual double Circumference()=0;
	virtual void print()=0;
	virtual bool IsValid()const;

private:
	static const int UnknownValue ;
};

class Circle:public Shape
{public:
	Circle(Point &a, double b);
	~Circle()
	{};
	double Area();
	double Circumference();
	void print();
	virtual bool IsValid(Circle &c)  ;
	Point mycenter() 
	{
		return center;
	}
	double myradius()
	{
		return radius;
	}
private:
    Point center;
	double radius;
};
class Polygon:public Shape
{
public:
	Polygon(std::vector<Edge*>&edges);
	~Polygon()
	{};
   double Circumference();
   double Area();
	void print();
	virtual bool IsValid() ;
private:
	std::vector<Edge*>edges_;
};
class And:public Shape
{public:
	And(Shape*s1, Shape*s2) :s1_(s1), s2_(s2){};
	 double Circumference() ;
	 void print() ;
	 double Area();
	 Point point1();
	 Point point2();
private:
	Shape* s1_;
	Shape* s2_;
};
class Or:public Shape
{public:
	Or(Shape* s1, Shape* s2) :s3_(s1), s4_(s2) {};
	double Circumference();
	double Area();
	void print();
	Point point1();
	Point point2();
private:
	Shape* s3_;
	Shape* s4_;
};
inline  And operator&(Shape& s1, Shape& s2)
{
	And a(&s1, &s2);
	return  a;
}
inline Or operator|(Shape&s1,Shape&s2)
{
	Or b(&s1, &s2);
	return b;
}
#endif