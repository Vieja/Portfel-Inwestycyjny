#ifndef Aktywo_hpp
#define Aktywo_hpp

#include <iostream>
using namespace std;

class Aktywo {
private:
    string nazwa;
    double kapital; // początkowy
public:
    string getNazwa();
    void setNazwa(string n);
    double getKapital();
    void setKapital(double k);
    virtual double ileZarobie(int k)=0;
    virtual void info()=0;
};

#endif
