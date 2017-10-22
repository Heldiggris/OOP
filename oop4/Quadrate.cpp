#include "Quadrate.h"
#include <iostream>
#include <cmath> 
Quadrate::Quadrate() : Quadrate(0) {
}

Quadrate::Quadrate(size_t i) : side(i) {
	if (side < 0) {
		std::cerr << "Error: sides should be > 0." << std::endl;
	}
}

Quadrate::Quadrate(std::istream &is) {
	is >> side;
	if (side < 0) {
		std::cerr << "Error: sides should be > 0." << std::endl;
	}
}

Quadrate::Quadrate(const Quadrate& orig) {
	side = orig.side;
}

size_t Quadrate::Square() {
	if (side < 0) {
		std::cerr << "Error: sides should be > 0." << std::endl;
		return 0;
	}
	return side * side;
}

void Quadrate::Print() {
	std::cout << "Квадрат: " << "a = " << side << std::endl;
}

Quadrate::~Quadrate() {
}