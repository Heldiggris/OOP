#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h" 
class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(double big_base, double small_base, double left_side, double right_side);
	Trapeze(const Trapeze& orig);

	double Square() override;
	void   Print() override;
	virtual ~Trapeze();
private:
	double base_big;
	double base_small;
	double side_left;
	double side_right;
};
#endif /* TRAPEZE_H */ 					