#include "Kontrakt.hpp"

int Kontrakt::getCzas() {
    return czas;
}
void Kontrakt::setCzas(int k) {
    czas = k;
}

double Kontrakt::getCena() {
    return cena;
}
void Kontrakt::setCena(double k) {
    cena = k;
}

double Kontrakt::ileZarobie(int miesiace) {
    if (miesiace>czas) return cena;
    else return getKapital();
}

void Kontrakt::info() {
    cout <<"\nAktualne wartosci kontraktu:\n"
         <<"[Nazwa] "<<getNazwa()<<"\n"
         <<"[Cena zakupu] "<<getKapital()<<"\n"
         <<"[Antycypowany czas sprzedazy] "<<getCzas()<<"\n"
         <<"[Antycypowana cena sprzedazy] "<<getCena()<<"\n\n";
}
