#include "FunduszDywidenda.hpp"

double FunduszDywidenda::getDywidenda() {
    return dywidenda;
}
void FunduszDywidenda::setDywidenda(double n) {
    dywidenda = n;
}

double FunduszDywidenda::ileZarobie(int miesiace) {
    double temp = miesiace;
    temp = temp/12;
    double lata = miesiace/12;
    double wynik = 1 + (getOprocentowanie()/100)/12;
    return wynik = getKapital() * pow(wynik,temp*12) + dywidenda*lata;


}

void FunduszDywidenda::info() {
    cout <<"\nAktualne wartosci jednostki funduszu z dywidenda:\n"
         <<"[Nazwa] "<<getNazwa()<<"\n"
         <<"[Kapital] "<<getKapital()<<"\n"
         <<"[Oprocentowanie] "<<getOprocentowanie()<<"\n"
         <<"[Dywidenda] "<<getDywidenda()<<"\n";
}
