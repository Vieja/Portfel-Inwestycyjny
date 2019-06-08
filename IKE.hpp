#ifndef IKE_hpp
#define IKE_hpp

#include <iostream>
#include <math.h>
#include "Aktywo.hpp"
using namespace std;

class IKE: public Aktywo{
private:
    double oprocentowanie;
public:
    double getOprocentowanie();
    void setOprocentowanie(double o);
    double ileZarobie(int c);
    void info();

};

#endif
