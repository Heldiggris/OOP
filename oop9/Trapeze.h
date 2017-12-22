#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Figure.h" 
class Trapeze : public Figure {
public:
    Trapeze();
    Trapeze(std::istream &is);
    Trapeze(size_t big_base, size_t small_base, size_t left_side, size_t right_side);
    Trapeze(const Trapeze& orig);

    friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
    size_t Square() override;
    void   Print() override;
    virtual ~Trapeze();
private:
    size_t base_big;
    size_t base_small;
    size_t side_left;
    size_t side_right;
};

bool CheckTrapeze(size_t base_big, size_t base_small, size_t side_left, size_t side_right);

#endif /* TRAPEZE_H */