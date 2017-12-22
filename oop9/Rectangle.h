#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>
#include <cmath> 
#include "Figure.h"


class Rectangle : public Figure {
public:
    Rectangle& operator++();
    friend Rectangle operator+(const Rectangle& left,const Rectangle& right);
    friend bool operator==(const Rectangle& left, const Rectangle& right);
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
    friend std::istream& operator>>(std::istream& is, Rectangle& obj);
    Rectangle& operator=(const Rectangle& right);
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(size_t i, size_t j);
	Rectangle(const Rectangle& orig);
	size_t Square() override;
	void Print() override;
	virtual ~Rectangle();
private:
	size_t side_a;
	size_t side_b;
};
#endif /* RECTANGLE_H */ 					