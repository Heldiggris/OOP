#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h" 
class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(double i, double jW);
	Rectangle(const Rectangle& orig);

	double Square() override;
	void   Print() override;
	virtual ~Rectangle();
private:
	double side_a;
	double side_b;
};
#endif /* RECTANGLE_H */ 					