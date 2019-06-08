#include "IKE.hpp"

double IKE::getOprocentowanie() {
    return oprocentowanie;
}
void IKE::setOprocentowanie(double k) {
    oprocentowanie = k;
}

double IKE::ileZarobie(int miesiace) {
    return 0;
}

void IKE::info() {
    cout <<"\nAktualne wartosci IKE:\n"
         <<"[Nazwa] "<<getNazwa()<<"\n"
         <<"[Kapital] "<<getKapital()<<"\n"
         <<"[Oprocentowanie w skali roku] "<<getOprocentowanie()<<"\n\n";
}

