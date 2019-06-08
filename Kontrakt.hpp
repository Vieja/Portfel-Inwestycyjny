#ifndef Kontrakt_hpp
#define Kontrakt_hpp

#include <iostream>
#include <math.h>
#include "Aktywo.hpp"
using namespace std;

class Kontrakt: public Aktywo{
private:
    int czas;
    double cena;
public:
    int getCzas();
    void setCzas(int o);
    double getCena();
    void setCena(double o);
    double ileZarobie(int c);
    void info();

};

#endif
