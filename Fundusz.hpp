#ifndef Fundusz_hpp
#define Fundusz_hpp

#include <iostream>
#include <math.h>
#include "Aktywo.hpp"
using namespace std;

class Fundusz: public Aktywo{
private:
    double oprocentowanie;
public:
    double getOprocentowanie();
    void setOprocentowanie(double o);
    virtual void setDywidenda(double o);
    virtual double ileZarobie(int c);
    virtual void info();

};

#endif
