#ifndef QUADRATE_H
#define QUADRATE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Quadrate : public Figure {
public:               
    Quadrate();
    Quadrate(std::istream &is);
    Quadrate(double i);
    Quadrate(const Quadrate& orig);

    double Square() override;
    void   Print() override;
    virtual ~Quadrate();
private:
    double side;
};
#endif /* QUADRATE_H */