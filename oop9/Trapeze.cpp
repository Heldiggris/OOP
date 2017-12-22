#include "Trapeze.h"
Trapeze::Trapeze() : Trapeze(0, 0, 0, 0) {
}

Trapeze::Trapeze(size_t big_base, size_t small_base, size_t left_side, size_t right_side) : base_big(big_base), base_small(small_base), side_left(left_side), side_right(right_side) {
    if (base_small > base_big) {
        std::swap(base_small, base_big);
    }
    if(base_small < 0 || base_big < 0 || side_left < 0 || side_right < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Trapeze::Trapeze(std::istream &is) {
    is >> base_big;
    is >> base_small;
    is >> side_left;
    is >> side_right;
    if (base_small > base_big) {
        std::swap(base_small, base_big);
    }
    if(base_small < 0 || base_big < 0 || side_left < 0 || side_right < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Trapeze::Trapeze(const Trapeze& orig) {
    base_big = orig.base_big;
    base_small = orig.base_small;
    side_left = orig.side_left;
    side_right = orig.side_right;
}

size_t Trapeze::Square() {
    if (base_big > base_small && base_small > 0 && base_big != base_small) {
        return ((base_small + base_big) / 2) * sqrt(side_left * side_left -
            pow((side_left * side_left - side_right * side_right) / (base_big - base_small) + base_big - base_small, 2) / 4);
    }
    else if (base_small <= 0 || base_big <= 0 || side_left <= 0 || side_right <= 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    else {
        std::cerr << "Error: The figure is not a trapeze" << std::endl;
    }
    return 0;
}

void Trapeze::Print() {
    std::cout << "Трапеция: " << "big_base = " << base_big << ", small_base = " << base_small << ", left_side = " << side_left << ", right_side = " << side_right << std::endl;
}

Trapeze::~Trapeze() {
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj) {
    os << "big_base = " << obj.base_big << ", small_base = " << obj.base_small << ", left_side = " << obj.side_left << ", right_side = " << obj.side_right << std::endl;
    return os;
}

bool CheckTrapeze(size_t base_big, size_t base_small, size_t side_left, size_t side_right) {
    if (base_big <= base_small) {
        return false;
    }
    if ((side_left * side_left -
                    pow((side_left * side_left - side_right * side_right) /
                         (base_big - base_small) + base_big - base_small, 2) / 4) > 0) {
        return true;
    }
    return false;
}