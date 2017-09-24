#include "Rectangle.h"
#include <iostream>
#include <cmath> 
Rectangle::Rectangle() : Rectangle(0.0, 0.0) {
}

Rectangle::Rectangle(double i, double j) : side_a(i), side_b(j) {
    std::cout << "Rectangle created" << std::endl;
    if (side_a < 0.0 || side_b < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Rectangle::Rectangle(std::istream &is) {
    is >> side_a;
    is >> side_b;
    if (side_a < 0.0 || side_b < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    std::cout << "Rectangle created" << std::endl;
}

Rectangle::Rectangle(const Rectangle& orig) {
    side_a = orig.side_a;
    side_b = orig.side_b;
    std::cout << "Rectangle copy created" << std::endl;
}

double Rectangle::Square() {
    if (side_a < 0.0 || side_b < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
        return 0.0;
    }
    return side_a * side_b;
}

void Rectangle::Print() {
    std::cout << "a = " << side_a << ", b = " << side_b << std::endl;
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}