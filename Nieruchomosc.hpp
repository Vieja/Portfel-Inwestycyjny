#ifndef Nierychomosc_hpp
#define Nieruchomosc_hpp

#include <iostream>
#include <math.h>
#include "Aktywo.hpp"
using namespace std;

class Nieruchomosc: public Aktywo{
private:
    double cena;
public:
    double getCena();
    void setCena(double o);
    double ileZarobie(int c);
    void info();

};

#endif
