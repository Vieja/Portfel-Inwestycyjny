#include "Fundusz.hpp"

double Fundusz::getOprocentowanie() {
    return oprocentowanie;
}
void Fundusz::setOprocentowanie(double n) {
    oprocentowanie = n;
}

void Fundusz::setDywidenda(double n) {}

double Fundusz::ileZarobie(int miesiace) {
    double lata = miesiace/12;
    double wynik = 1 + (oprocentowanie/100)/12;
    return wynik = getKapital() * pow(wynik,lata*12);

}

void Fundusz::info() {
    cout <<"\nAktualne wartosci jednostki funduszu:\n"
         <<"[Nazwa] "<<getNazwa()<<"\n"
         <<"[Kapital] "<<getKapital()<<"\n"
         <<"[Oprocentowanie] "<<getOprocentowanie()<<"\n\n";
}
