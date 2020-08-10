#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
private :
	int width, height;
public :
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	void scale() {
		cout << "Rectangle Draw" 
			<< endl;
	}
};

