#ifndef Lokata_hpp
#define Lokata_hpp

#include <iostream>
#include <math.h>
#include "Aktywo.hpp"
using namespace std;

class Lokata: public Aktywo{
private:
    double oprocentowanie;
    int czas;
    int kapitalizacja;
public:
    double getOprocentowanie();
    void setOprocentowanie(double o);
    int getCzas();
    void setCzas(int c);
    int getKapitalizacja();
    void setKapitalizacja(int c);
    double ileZarobie(int c);
    void info();

};

#endif

