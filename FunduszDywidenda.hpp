#ifndef FunduszDywidenda_hpp
#define FunduszDywidenda_hpp

#include <iostream>
#include <math.h>
#include "Fundusz.hpp"
using namespace std;

class FunduszDywidenda: public Fundusz{
private:
    double dywidenda;
public:
    double getDywidenda();
    void setDywidenda(double o);
    double ileZarobie(int c);
    void info();

};

#endif
