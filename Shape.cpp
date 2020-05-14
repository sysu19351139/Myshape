#include"Shape.h"
#include<cmath>
using namespace std; 
const int Shape::UnknownValue=-1;
 bool Shape::IsValid()const
 {
	 return UnknownValue;
 }
Circle::Circle(Point &a,double r):center(a),radius(r)
{
	cout << "Circle constructor" << endl;
}
double Circle::Area()
{
	return (3.14 * radius * radius);
}
double Circle::Circumference()
{
	return (3.14 * radius);
}
void Circle::print()
{
	cout << "圆心";
	center.print();
	cout << "半径：" << radius << endl;
	cout << "周长：" << Circumference() << endl;
	cout << "面积：" << Area()<<endl<<endl;
}
bool Circle::IsValid(Circle&c)
{
	double length = sqrt((center.getx()- c.center.getx()) * (center.getx() - c.center.getx())+ center.gety() * center.gety());
	if (length < (radius + c.radius))
	{
		return true;
	}
	else
		return false;
}
Polygon::Polygon(std::vector<Edge*>&edges)
{
	cout << "Polygon constructor" << endl;
	for(vector<Edge*>::iterator iter=edges.begin();iter<edges.end();iter++)
	{
		edges_.push_back(*iter);
	}
}
double Polygon::Circumference()
{
	double lengths=0;
	vector<Edge*>::iterator iter = edges_.begin();
	for(;iter<edges_.end();iter++)
	{
		lengths = lengths + (**iter).Length();
	}
	return lengths;
}
double Polygon::Area()
{
	return UnknownValue;
}
void Polygon::print()
{
	cout << "面积:" << Area()<<endl;
	cout << "周长：" << Circumference() << endl;
	int i = 1;
	vector<Edge*>::iterator iter = edges_.begin();
	for (; iter < edges_.end(); iter++)
	{
		cout << "第" << i << "条边"<<endl;
		(**iter).print();
		i++;
	}
	cout << endl;

}
 bool Polygon::IsValid()
 {
	 return UnknownValue;
}
 Point And::point1()                                      
 {
	 Circle* c1 = dynamic_cast<Circle*>(s1_);
	 Circle* c2 = dynamic_cast<Circle*>(s2_);
	 if (c1 != 0) { 
		 double x = (c1->mycenter()).getx();
		 double y = (c1->mycenter()).gety();
		 double a = (c2->mycenter()).getx();
		 double b = (c2->mycenter()).gety();
		 double x1 = (a + x) / 2;
		 double y1 = (b + y) / 2;
		 double length2 = c1->myradius() * c1->myradius() - (x1 - x) * (x1 - x) - (y1 - y) * (y1 - y);
		 double l = sqrt(length2);
		 double y2 = y1 + l;
		 Point p1(x1, y2);
		 return p1;
	 }
	 else {
		 Point p1(0, 0);
		 return p1;
	 }
 }
 Point And::point2()                                     
 {
	 Circle* c1 = dynamic_cast<Circle*>(s1_);
	 Circle* c2 = dynamic_cast<Circle*>(s2_);
	 if (c1 != 0) {
		 double x = (c1->mycenter()).getx();
		 double y = (c1->mycenter()).gety();
		 double a = (c2->mycenter()).getx();
		 double b = (c2->mycenter()).gety();
		 double x1 = (a + x) / 2;
		 double y1 = (b + y) / 2;
		 double length2 = c1->myradius() * c1->myradius() - (x1 - x) * (x1 - x) - (y1 - y) * (y1 - y);
		 double l = sqrt(length2);
		 double y2 = y1 - l;
		 Point p2(x1, y2);
		 return p2;
	 }
	 else {
		 Point p1(0, 0);
		 return p1;
	 }
 }

 double And::Area()                                     
 {
	 Circle* c1 = dynamic_cast<Circle*>(s1_);
	 Circle* c2 = dynamic_cast<Circle*>(s2_);
	 if (c1 != 0)
	 {
		 double x = (c1->mycenter()).getx();
		 double y = (c1->mycenter()).gety();
		 double x_ = (c2->mycenter()).getx();
		 double y_ = (c2->mycenter()).gety();
		 double length_2 = (x - x_) * (x - x_) + (y - y_) * (y - y_);
		 double length1_2 = c1->myradius() * c1->myradius() - length_2 / 4;
		 double t = asin(sqrt(length_2) / (c1->myradius() * 2));
		 double area = 2 * t * c1->myradius() * c1->myradius() - sqrt(length_2) * sqrt(length1_2);
		 return area;
	 }
	 else 
	 {
		 return -1;
	 }
 }
 double And::Circumference()                                         
 {
	 Circle* c1 = dynamic_cast<Circle*>(s1_);
	 Circle* c2 = dynamic_cast<Circle*>(s2_);
	 if (c1 != 0)
	 {
		 double x = (c1->mycenter()).getx();
		 double y = (c1->mycenter()).gety();
		 double x_ = (c2->mycenter()).getx();
		 double y_= (c2->mycenter()).gety();
		 double length_2 = (x - x_) * (x - x_) + (y - y_) * (y - y_);
		 double circumference = 2 * asin(sqrt(length_2) /( c1->myradius()*2)) * c1->myradius();
		 return  circumference;
	 }
	 else {
		 return -1;
	 }
 } 
 void And:: print()
 {
	 Circle* c1 = dynamic_cast<Circle*>(s1_);
	 Circle* c2 = dynamic_cast<Circle*>(s2_);
	 if(c1!=0)
	 {
		 cout << "圆的交:"<<endl<<"交点";
		 point1().print();
		 cout << "交点";
		 point2().print();
		 cout << "the circumference:" << Circumference()<<endl;
		 cout << "the area:" << Area() << endl;
	 }
	 else 
	 {
		 cout << "多边形的交" << endl;
	 }
 }
 
 Point Or::point1()                                    
 {
	 Circle* c1 = dynamic_cast<Circle*>(s3_);
	 Circle* c2 = dynamic_cast<Circle*>(s4_);
	 if (c1 != 0) {
		 double x = (c1->mycenter()).getx();
		 double y = (c1->mycenter()).gety();
		 double a = (c2->mycenter()).getx();
		 double b = (c2->mycenter()).gety();
		 double x1 = (a + x) / 2;
		 double y1 = (b + y) / 2;
		 double length2 = c1->myradius() * c1->myradius() - (x1 - x) * (x1 - x) - (y1 - y) * (y1 - y);
		 double l = sqrt(length2);
		 double y2 = y1 + l;
		 Point p1(x1, y2);
		 return p1;
	 }
	 else {
		 Point p1(0, 0);
		 return p1;
	 }
 }
 Point Or::point2()                                     
 {
	 Circle* c1 = dynamic_cast<Circle*>(s3_);
	 Circle* c2 = dynamic_cast<Circle*>(s4_);
	 if (c1 != 0) {
		 double x = (c1->mycenter()).getx();
		 double y = (c1->mycenter()).gety();
		 double a = (c2->mycenter()).getx();
		 double b = (c2->mycenter()).gety();
		 double x1 = (a + x) / 2;
		 double y1 = (b + y) / 2;
		 double length2 = c1->myradius() * c1->myradius() - (x1 - x) * (x1 - x) - (y1 - y) * (y1 - y);
		 double l = sqrt(length2);
		 double y2 = y1 - l;
		 Point p2(x1, y2);
		 return p2;
	 }
	 else {
		 Point p1(0, 0);
		 return p1;
	 }
 }
 double Or::Area()                                          
 {
	 Circle* c1 = dynamic_cast<Circle*>(s3_);
	 Circle* c2 = dynamic_cast<Circle*>(s4_);
	 And a(s3_, s4_);
	 if (c1 != 0)
	 {
		 double area = 6.18 * c1->myradius() * c1->myradius() - a.Area();
		 return area;
	 }
	 else
	 {
		 return -1;
	 }
	 

 }
 double Or::Circumference()                                       
 {
	 And a(s3_, s4_);
	 Circle* c1 = dynamic_cast<Circle*>(s3_);
	 double circumference = 2 * 3.14 * c1->myradius() - a.Circumference();
	 return circumference;
 }
 void Or::print()
 {
	 Circle* c1 = dynamic_cast<Circle*>(s3_);
	 Circle* c2 = dynamic_cast<Circle*>(s4_);
	 if (c1 != 0)
	 {
		 cout << "圆的并"<<endl<<"交点";
		 point1().print();
		 cout << "交点";
		 point2().print();
		 cout << "the circumference:" << Circumference()<<endl;
		 cout << "the area:" << Area()<<endl;
	 }
	 else
	 {
		 cout << "多边形的并" << endl;

	 }
 }
