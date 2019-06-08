#include "Lokata.hpp"

double Lokata::getOprocentowanie() {
    return oprocentowanie;
}
void Lokata::setOprocentowanie(double n) {
    oprocentowanie = n;
}

int Lokata::getCzas() {
    return czas;
}
void Lokata::setCzas(int k) {
    czas = k;
}

int Lokata::getKapitalizacja() {
    return kapitalizacja;
}
void Lokata::setKapitalizacja(int k) {
    kapitalizacja = k;
}

double Lokata::ileZarobie(int miesiace) {
    double temp;
    if (miesiace >= czas) temp = czas; else temp = miesiace;
    double lata = temp/12;
    double wynik = 1 + (oprocentowanie/100)/kapitalizacja;
    return wynik = getKapital() * pow(wynik,lata*kapitalizacja);

}

void Lokata::info() {
    cout <<"\nAktualne wartosci lokaty:\n"
         <<"[Nazwa] "<<getNazwa()<<"\n"
         <<"[Kapital] "<<getKapital()<<"\n"
         <<"[Oprocentowanie] "<<getOprocentowanie()<<"\n"
         <<"[Kapitalizacja] "<<getKapitalizacja()<<"\n"
         <<"[Czas] "<<getCzas()<<"\n\n";
}
