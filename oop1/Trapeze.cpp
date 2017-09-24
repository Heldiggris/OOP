#include "Trapeze.h"
#include <iostream>
#include <cmath> 
Trapeze::Trapeze() : Trapeze(0.0, 0.0, 0.0, 0.0) {
}

Trapeze::Trapeze(double big_base, double small_base, double left_side, double right_side) : base_big(big_base), base_small(small_base), side_left(left_side), side_right(right_side) {
    if (base_small > base_big) {
        std::swap(base_small, base_big);
    }
    if(base_small < 0.0 || base_big < 0.0 || side_left < 0.0 || side_right < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    std::cout << "Trapeze created" << std::endl;
}

Trapeze::Trapeze(std::istream &is) {
    is >> base_big;
    is >> base_small;
    is >> side_left;
    is >> side_right;
    if (base_small > base_big) {
        std::swap(base_small, base_big);
    }
    if(base_small < 0.0 || base_big < 0.0 || side_left < 0.0 || side_right < 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    std::cout << "Trapeze created" << std::endl;
}

Trapeze::Trapeze(const Trapeze& orig) {
    base_big = orig.base_big;
    base_small = orig.base_small;
    side_left = orig.side_left;
    side_right = orig.side_right;
    std::cout << "Trapeze copy created" << std::endl;
}

double Trapeze::Square() {
    if (base_big > base_small && base_small > 0.0 && base_big != base_small) {
        return double(((base_small + base_big) / 2.0) * sqrt(side_left * side_left - 1.0 / 4.0 * 
            pow((side_left * side_left - side_right * side_right) / (base_big - base_small) + base_big - base_small, 2)));
    }
    else  if(base_small <= 0.0 || base_big <= 0.0 || side_left <= 0.0 || side_right <= 0.0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    else {
        std::cerr << "Error: The figure is not a trapeze" << std::endl;
    }
    return 0.0;
}

void Trapeze::Print() {
    std::cout << "big_base = " << base_big << ", small_base = " << base_small << ", left_side = " << side_left << ", right_side = " << side_right << std::endl;
}

Trapeze::~Trapeze() {
    std::cout << "Trapeze deleted" << std::endl;
}