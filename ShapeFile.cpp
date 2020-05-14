#include"ShapeFile.h"
#include"Shape.h"
using namespace std;
ShapeFile::ShapeFile(ifstream& is) 
{
	string text, all;
	while (getline(is, text))
	{
		all += text;
	}
	string::size_type start1 = all.find_first_of("1");
	string::size_type start = all.find_first_of("(", start1);
	vector<Point>points;
	while ( start < all.find("#circle"))                                
	{auto end= all.find_first_of(")", start);
		string _x;
		_x.assign(all, start+1, 1);
		double x = stod(_x);
		string _y;
		_y.assign(all, start + 3, 1);
		double y = stod(_y);
		Point p(x, y);
		points.push_back(p);
		start = all.find_first_of("(", end);
	}
	start = all.find("Circle");
	start = all.find_first_of("P", start);
	while ( start < all.find("#polygon"))                             
	{
		string::size_type end = all.find_first_of("C", start);
		string p, k;
		p.assign(all, start + 1, 1);
		k.assign(all, start + 3, 1);
		double _p = stod(p);
		double _k = stod(k);                   
		for (double i = 1;i<10; i++)
		{
			Point a(0, 0);
				if (i == _p)
				{
					shapes_.push_back(new Circle(points[i-1], _k));
					break;
				}
				
		}
		start = all.find_first_of("P", end);
	}
	auto start2 = all.find("vertices");
	start2 = all.find("gon", start2);
	start = all.find_first_of("P", start2);                     
	for (int i = 0; i < 3; i++)
	{
		auto mypoint = new vector<Point>;
		auto myedge = new vector<Edge*>;
		while (start < all.find("Polygon", start2))
		{
			string::size_type end_ = all.find_first_of(",", start);
			string p;
			if(p.assign(all, start + 1, 2)=="10")
			{
				p.assign(all, start + 1, 2);
			}
			else
			{
				p.assign(all, start + 1, 1);
			}
			double _p = stod(p);
			for (double i = 1;i<11; i++)
			{
				
					if (i == _p) 
					{
						mypoint->push_back(points[i-1]);
						break;
				    }
			}
			start = all.find_first_of("P", end_);
		}
		start2 = all.find("gon", start2+3);
		start = all.find_first_of("P", start2);
		vector<Point>::iterator it = mypoint->begin();
		for (; it < mypoint->end(); it++)
		{ 
			if(it!=mypoint->end()-1)
		{
			myedge->push_back(new Edge(*it, *(it + 1)));
		}
		else
		{
			myedge->push_back(new Edge((*it), *(mypoint->begin())));
		}

		}
		shapes_.push_back(new Polygon(*myedge));
		delete mypoint;
		delete myedge;
	}
}
void ShapeFile::Generate()
{
	auto it1 = shapes_.begin();                                             
	for (; it1 < shapes_.end() - 1; it1++)
	{
		for (auto it2 = it1 + 1; it2 < shapes_.end(); it2++)
		{
			if (typeid(*(*it1)) == typeid(*(*it2)))
			{
				compositeShapes_.push_back(new And(*(*it1) & *(*it2)));
			}
		}
		for (auto it2 = it1 + 1; it2 < shapes_.end(); it2++)                      
		{
			if (typeid(*(*it1)) == typeid(*(*it2)))
			{
				compositeShapes_.push_back(new Or(*(*it1) | *(*it2)));
			}
		}
	}
}

    void ShapeFile::print()
	{
	auto it3 = shapes_.begin();
	int i = 1;
	for (; it3 < shapes_.end(); it3++)                                   
	{
		cout << "\"Shape" << i << ":\"" << endl;
		(*it3)->print();
		i++;
	}
	int j = 1;
	auto it4 = compositeShapes_.begin();
	for (; it4< compositeShapes_.end(); it4++)                         
	{
		cout << " compositeShapes" << j << ":" << endl;
		(*it4)->print();
		j++;
	}

}