#include "Nieruchomosc.hpp"

double Nieruchomosc::getCena() {
    return cena;
}
void Nieruchomosc::setCena(double k) {
    cena = k;
}

double Nieruchomosc::ileZarobie(int miesiace) {
    return getKapital() + getCena()*miesiace;
}

void Nieruchomosc::info() {
    cout <<"\nAktualne wartosci nieruchomosci:\n"
         <<"[Nazwa] "<<getNazwa()<<"\n"
         <<"[Cena zakupu] "<<getKapital()<<"\n"
         <<"[Antycypowany wzrost wartosci na miesiac] "<<getCena()<<"\n\n";
}
