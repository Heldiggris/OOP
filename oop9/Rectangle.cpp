#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {
}

Rectangle::Rectangle(size_t i, size_t j) : side_a(i), side_b(j) {
    // std::cout << "Rectangle created" << std::endl;
    if (side_a < 0 || side_b < 0) {
        std::cerr << "Error: sides should be > 0."<< std::endl;
    }
}

Rectangle::Rectangle(std::istream &is) {
    is >> side_a;
    is >> side_b;
    if (side_a < 0 || side_b < 0) {
        std::cerr << "Error: sides should be > 0."<< std::endl;
    }
    // std::cout << "Rectangle created" << std::endl;
}

Rectangle::Rectangle(const Rectangle& orig) {
    side_a = orig.side_a;
    side_b = orig.side_b;
    // std::cout << "Rectangle copy created" << std::endl;
}

size_t Rectangle::Square() {
    if (side_a < 0 || side_b < 0) {
        std::cerr << "Error: sides should be > 0.";
        return 0;
    }
    return side_a * side_b;
}

void Rectangle::Print() {
    std::cout << "Прямоугольник: " << "a = " << side_a << ", b = " << side_b << std::endl;
}

Rectangle::~Rectangle() {
    // std::cout << "Rectangle deleted" << std::endl;
}

Rectangle& Rectangle::operator=(const Rectangle& right) {
    if (this == &right)
        return *this;
    side_a = right.side_a;
    side_b = right.side_b;
    return *this;
}

Rectangle& Rectangle::operator++() {
    side_a++;
    side_b++;
    return *this;
}

Rectangle operator+(const Rectangle& left, const Rectangle& right) {
    return Rectangle(left.side_a + right.side_a, left.side_b + right.side_b);
}


bool operator==(const Rectangle& left, const Rectangle& right) {
    return (left.side_a == right.side_a and left.side_b == right.side_b) or (left.side_a == right.side_b and left.side_b == right.side_a);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
    os << "a = " << obj.side_a << ", b = " << obj.side_b << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
    is >> obj.side_a;
    is >> obj.side_b;
    return is;
}