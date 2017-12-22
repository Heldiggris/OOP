#include "Quadrate.h"
#include <iostream>
#include <cmath> 
Quadrate::Quadrate() : Quadrate(0.0) {
}

Quadrate::Quadrate(double i) : side(i) {
    std::cout << "Quadrate created: " << side << std::endl;
    if (side < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Quadrate::Quadrate(std::istream &is) {
    is >> side;
    std::cout << "Quadrate created: " << side << std::endl;
    if (side < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Quadrate::Quadrate(const Quadrate& orig) {
    side = orig.side;
    std::cout << "Quadrate copy created" << std::endl;
}

double Quadrate::Square() {
    if (side < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
        return 0.0;
    }
    return side * side;
}

void Quadrate::Print() {
    std::cout << "a = " << side << std::endl;
}

Quadrate::~Quadrate() {
    std::cout << "Quadrate deleted" << std::endl;
}