#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Aktywo.hpp"
#include "Lokata.hpp"
#include "Fundusz.hpp"
#include "FunduszDywidenda.hpp"
#include "Kontrakt.hpp"
#include "Nieruchomosc.hpp"
#include "IKE.hpp"
#include "Portfel.cpp"

using namespace std;

ifstream wczytaj;
ofstream zapisz;

void help() {
    cout << "Dostepne opcje:\n"
         << "/help - wyswietl pomoc\n"
         << "/dodaj - dodaj aktywo\n"
         << "/usun - usun aktywo\n"
         << "/edytuj - wyswetla szczegolowe wartosci aktywa i pozwala na ich edycje\n"
         << "/wyswietl - wyswietl wszystkie swoje aktywa\n"
         << "/oszacuj - oszacuj swoje oszczednosci\n"
         << "/exit - aby zakonczyc\n\n"
;
}

int dodajLokata(Lokata &lokata) {
    string text;
    stringstream ss1,ss2,ss3,ss4;
    string nazwa; double kapital, oprocentowanie; int kapitalizacja, czas;
    cout << "Nazwa: "; cin >> nazwa;
    cout << "Kapital poczatkowy: <double> "; cin >> text;
            ss1 << text;
            ss1 >> kapital; if (kapital == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajLokata(lokata); return 0;}
    cout << "Oprocentowanie w skali roku (w procentach): <double> "; cin >> text;
            ss2 << text;
            ss2 >> oprocentowanie; if (oprocentowanie == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajLokata(lokata); return 0;}
    cout << "Liczba kapitalizacji w roku: <int> "; cin >> text;
            ss3 << text;
            ss3 >> kapitalizacja; if (kapitalizacja == NULL || text.find('.') != -1) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajLokata(lokata); return 0;}
    cout << "Czas trwania lokaty w miesiacach: <int> "; cin >> text;
            ss4 << text;
            ss4 >> czas; if (czas == NULL || text.find('.') != -1) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajLokata(lokata); return 0;}
    lokata.setNazwa(nazwa);
    lokata.setKapital(kapital);
    lokata.setOprocentowanie(oprocentowanie);
    lokata.setKapitalizacja(kapitalizacja);
    lokata.setCzas(czas);
    cout << "Dodano "<<lokata.getNazwa()<<endl;
    return 0;
}

int dodajFundusz(Fundusz &fundusz,bool czyDywidenda) {
    string text;
    stringstream ss1,ss2,ss3;
    string nazwa; double kapital, oprocentowanie, dywidenda;
    cout << "Nazwa: "; cin >> nazwa;
    cout << "Kapital poczatkowy: <double> "; cin >> text;
            ss1 << text;
            ss1 >> kapital; if (kapital == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajFundusz(fundusz,czyDywidenda); return 0;}
    cout << "Oprocentowanie w skali roku (w procentach): <double> "; cin >> text;
            ss2 << text;
            ss2 >> oprocentowanie; if (oprocentowanie == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajFundusz(fundusz,czyDywidenda); return 0;}
    if (czyDywidenda == 1) {
        cout << "Dywidenda: <double> "; cin >> text;
        ss3 << text;
        ss3 >> dywidenda; if (dywidenda == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajFundusz(fundusz,czyDywidenda); return 0;}
    }
    fundusz.setNazwa(nazwa);
    fundusz.setKapital(kapital);
    fundusz.setOprocentowanie(oprocentowanie);
    if (czyDywidenda == 1) fundusz.setDywidenda(dywidenda);
    cout << "Dodano "<<fundusz.getNazwa()<<endl;
    return 0;
}

int dodajKontrakt(Kontrakt &kontrakt) {
    string text;
    stringstream ss1,ss2,ss3;
    string nazwa; double kapital, cena; int czas;
    cout << "Nazwa: "; cin >> nazwa;
    cout << "Cena zakupu: <double> "; cin >> text;
            ss1 << text;
            ss1 >> kapital; if (kapital == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajKontrakt(kontrakt); return 0;}
    cout << "Antycypowany czas sprzedazy (w miesiacach): <int> "; cin >> text;
            ss2 << text;
            ss2 >> czas; if (czas == NULL || text.find('.') != -1) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajKontrakt(kontrakt); return 0;}
    cout << "Antycypowana cena sprzedazy: <double> "; cin >> text;
            ss3 << text;
            ss3 >> cena; if (cena == NULL || cena < kapital) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajKontrakt(kontrakt); return 0;}
    kontrakt.setNazwa(nazwa);
    kontrakt.setKapital(kapital);
    kontrakt.setCzas(czas);
    kontrakt.setCena(cena);
    cout << "Dodano "<<kontrakt.getNazwa()<<endl;
    return 0;
}

int dodajNieruchomosc(Nieruchomosc &nieruchomosc) {
    string text;
    stringstream ss1,ss2;
    string nazwa; double kapital, cena;
    cout << "Nazwa: "; cin >> nazwa;
    cout << "Poczatkowa wartosc: <double> "; cin >> text;
            ss1 << text;
            ss1 >> kapital; if (kapital == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajNieruchomosc(nieruchomosc); return 0;}
    cout << "Antycypowany wzrost wartosci na miesiac: <double> "; cin >> text;
            ss2 << text;
            ss2 >> cena; if (cena == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajNieruchomosc(nieruchomosc); return 0;}
    nieruchomosc.setNazwa(nazwa);
    nieruchomosc.setKapital(kapital);
    nieruchomosc.setCena(cena);
    cout << "Dodano "<<nieruchomosc.getNazwa()<<endl;
    return 0;
}

int dodajIKE(IKE &ike) {
    string text;
    stringstream ss1,ss2;
    string nazwa; double kapital, oprocentowanie;
    cout << "Nazwa: "; cin >> nazwa;
    cout << "Kapital: <double> "; cin >> text;
            ss1 << text;
            ss1 >> kapital; if (kapital == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajIKE(ike); return 0;}
    cout << "Oprocentowanie w skali roku (w procentach): <double> "; cin >> text;
            ss2 << text;
            ss2 >> oprocentowanie; if (oprocentowanie == NULL) { cout <<"Niepoprawna wartosc, sprobuj jeszcze raz:\n\n"; dodajIKE(ike); return 0;}
    ike.setNazwa(nazwa);
    ike.setKapital(kapital);
    ike.setOprocentowanie(oprocentowanie);
    cout << "Dodano "<<ike.getNazwa()<<endl;
    return 0;
}

bool czyEdytowac() {
    string text;
    cout <<"\nCzy chcesz zmienic wartosci? <tak,nie>\n";
    cin >> text;
    if (text=="tak") {
        cout<<"Podaj nowe wartosci:\n";
        return true;
    } else return false;
}

void save(Portfel <Lokata> p1, Portfel <Fundusz> p2, Portfel <FunduszDywidenda> p3, Portfel <Kontrakt> p4,
          Portfel <Nieruchomosc> p5, Portfel <IKE> p6) {
    int i;
    ofstream zapisz;
    zapisz.open("dane.txt");

    zapisz << "Lokata\n";
    i = 0;
    while (i != p1.getCurrentSize() ) {
        Lokata lplik = p1.zKolei(i);
        zapisz<<lplik.getNazwa()<<" "<<lplik.getKapital()<<" "<<lplik.getOprocentowanie()<<" "<<lplik.getKapitalizacja()<<" "<<lplik.getCzas()<<"\n";
        i++;
    }

    zapisz << "Fundusz\n";
    i = 0;
    while (i != p2.getCurrentSize() ) {
        Fundusz fplik = p2.zKolei(i);
        zapisz<<fplik.getNazwa()<<" "<<fplik.getKapital()<<" "<<fplik.getOprocentowanie()<<"\n";
        i++;
    }

    zapisz << "FunduszDywidenda\n";
    i = 0;
    while (i != p3.getCurrentSize() ) {
        FunduszDywidenda ffplik = p3.zKolei(i);
        zapisz<<ffplik.getNazwa()<<" "<<ffplik.getKapital()<<" "<<ffplik.getOprocentowanie()<<" "<<ffplik.getDywidenda()<<"\n";
        i++;
    }

    zapisz << "Kontrakt\n";
    i = 0;
    while (i != p4.getCurrentSize() ) {
        Kontrakt kplik = p4.zKolei(i);
        zapisz<<kplik.getNazwa()<<" "<<kplik.getKapital()<<" "<<kplik.getCzas()<<" "<<kplik.getCena()<<"\n";
        i++;
    }

    zapisz << "Nieruchomosc\n";
    i = 0;
    while (i != p5.getCurrentSize() ) {
        Nieruchomosc nplik = p5.zKolei(i);
        zapisz<<nplik.getNazwa()<<" "<<nplik.getKapital()<<" "<<nplik.getCena()<<"\n";
        i++;
    }

    zapisz << "IKE\n";
    i = 0;
    while (i != p6.getCurrentSize() ) {
        IKE iplik = p6.zKolei(i);
        zapisz<<iplik.getNazwa()<<" "<<iplik.getKapital()<<" "<<iplik.getOprocentowanie()<<"\n";
        i++;
    }
    zapisz << "Koniec";
}

int main()
{
    int rozmiar = 50;
    Portfel <Lokata> PortfelLokata(rozmiar);
    Portfel <Fundusz> PortfelFundusz(rozmiar);
    Portfel <FunduszDywidenda> PortfelFunduszDywidenda(rozmiar);
    Portfel <Kontrakt> PortfelKontrakt(rozmiar);
    Portfel <Nieruchomosc> PortfelNieruchomosc(rozmiar);
    Portfel <IKE> PortfelIKE(rozmiar);

    wczytaj.open("dane.txt");

    if( wczytaj.good() ) {
        string napis;
        wczytaj >> napis;
        int a,b;
        double c,d,e;

        wczytaj >> napis;
        while (napis != "Fundusz") {
            wczytaj >> c >> d >> a >> b;
            Lokata plok;
            plok.setNazwa(napis);
            plok.setKapital(c);
            plok.setOprocentowanie(d);
            plok.setKapitalizacja(a);
            plok.setCzas(b);
            PortfelLokata+=plok;
            wczytaj >> napis;
        }

        wczytaj >> napis;
        while (napis != "FunduszDywidenda") {
            wczytaj >> c >> d;
            Fundusz flok;
            flok.setNazwa(napis);
            flok.setKapital(c);
            flok.setOprocentowanie(d);
            PortfelFundusz+=flok;
            wczytaj >> napis;
        }

        wczytaj >> napis;
        while (napis != "Kontrakt") {
            wczytaj >> c >> d >> e;
            FunduszDywidenda alok;
            alok.setNazwa(napis);
            alok.setKapital(c);
            alok.setOprocentowanie(d);
            alok.setDywidenda(e);
            PortfelFunduszDywidenda+=alok;
            wczytaj >> napis;
        }

        wczytaj >> napis;
        while (napis != "Nieruchomosc") {
            wczytaj >> c >> a >> d;
            Kontrakt blok;
            blok.setNazwa(napis);
            blok.setKapital(c);
            blok.setCzas(a);
            blok.setCena(d);
            PortfelKontrakt+=blok;
            wczytaj >> napis;
        }

        wczytaj >> napis;
        while (napis != "IKE") {
            wczytaj >> c >> d;
            Nieruchomosc clok;
            clok.setNazwa(napis);
            clok.setKapital(c);
            clok.setCena(d);
            PortfelNieruchomosc+=clok;
            wczytaj >> napis;
        }

        wczytaj >> napis;
        while (napis != "Koniec") {
            wczytaj >> c >> d;
            IKE dlok;
            dlok.setNazwa(napis);
            dlok.setKapital(c);
            dlok.setOprocentowanie(d);
            PortfelIKE+=dlok;
            wczytaj >> napis;
        }
    } else {
        cout << "Wystapil blad z otwieraniem pliku\n";
        return -1;
    }

    cout << "Witaj w swoim Portfelu Inwestycyjnym!" << endl;

    string text;
    help();
    while(1) {
        cin >> text;
        if (text=="/help") {
            help();
        } else if (text=="/exit") {
            return 0;
        } else if (text=="/wyswietl") {
            cout << "\nWyswietlam wszystkie Twoje aktywa\n";
            if (PortfelLokata.getCurrentSize() != 0) PortfelLokata.wyswietl("lokaty");
            if (PortfelFundusz.getCurrentSize() != 0) PortfelFundusz.wyswietl("jednostki uczestnictwa w funduszu bez dywidendy");
            if (PortfelFunduszDywidenda.getCurrentSize() != 0) PortfelFunduszDywidenda.wyswietl("jednostki uczestnictwa w funduszu z dywidenda");
            if (PortfelKontrakt.getCurrentSize() != 0) PortfelKontrakt.wyswietl("kontrakty");
            if (PortfelNieruchomosc.getCurrentSize() != 0) PortfelNieruchomosc.wyswietl("nieruchomosci");
            if (PortfelIKE.getCurrentSize() != 0) PortfelIKE.wyswietl("IKE");
        } else if (text=="/dodaj") {
            string typ;
            cout << "Jakie aktywo chcialbys dodac?\n"
                 << "   mozliwe opcje: lokata, fundusz, kontrakt, nieruchomosc, IKE\n";
            cin >> typ;

            if (typ=="lokata") {
                Lokata lokata;
                dodajLokata(lokata);
                PortfelLokata+=lokata;
            } else if (typ=="fundusz") {
                string text;
                cout <<"Czy jednostka uczestnictwa w funduszu jest z dywidenda? <tak,nie>;\n";
                cin >> text;
                if (text=="nie") {
                    Fundusz fundusz;
                    dodajFundusz(fundusz,0);
                    PortfelFundusz+=fundusz;
                } else if (text=="tak") {
                    FunduszDywidenda fundusz;
                    dodajFundusz(fundusz,1);
                    PortfelFunduszDywidenda+=fundusz;
                } else cout <<"Wprowadzono niepoprawna wartosc\n";
            } else if (typ=="kontrakt") {
                Kontrakt kontrakt;
                dodajKontrakt(kontrakt);
                PortfelKontrakt+=kontrakt;
            } else if (typ=="nieruchomosc") {
                Nieruchomosc nieruchomosc;
                dodajNieruchomosc(nieruchomosc);
                PortfelNieruchomosc+=nieruchomosc;
            } else if (typ=="IKE") {
                IKE ike;
                dodajIKE(ike);
                PortfelIKE+=ike;
            } else cout << "Wybrano niepoprawne aktywo\n";
        } else if (text=="/usun") {
            string typ;
            cout << "Jakie aktywo chcialbys usunac?\n"
                 << "   mozliwe opcje: lokata, jednostka funduszu, kontrakt, nieruchomosc, IKE\n";
            cin >> typ;
            string nazwa;
            cout << "Podaj nazwe aktywa do usuniecia:\n";
            cin >> nazwa;

            if (typ=="lokata") PortfelLokata-=nazwa;
            else if (typ=="fundusz") {
                int x = PortfelFundusz-=nazwa;
                if (x==-1) PortfelFunduszDywidenda-=nazwa;
            } else if (typ=="kontrakt") PortfelKontrakt-=nazwa;
            else if (typ=="nieruchomosc") PortfelNieruchomosc-=nazwa;
            else if (typ=="IKE") PortfelIKE-=nazwa;
            else cout << "Wybrano niepoprawne aktywo\n";

        } else if (text=="/edytuj") {
            string typ;
            cout << "Jakie aktywo chcialbys edytowac?\n"
                 << "   mozliwe opcje: lokata, jednostka funduszu, kontrakt, nieruchomosc, IKE\n";
            cin >> typ;
            string nazwa;
            cout << "Podaj nazwe aktywa do edycji:\n";
            cin >> nazwa;
            if (typ=="lokata") {
                int ind = PortfelLokata.znajdz(nazwa);
                if (czyEdytowac() == true) {
                    Lokata nowa;
                    dodajLokata(nowa);
                    PortfelLokata.podstaw(nowa,ind);
                }
            } else if (typ=="fundusz") {
                string odp;
                cout << "Czy wybrana jednostka funduszu jest z dywidenda? <tak,nie> ";
                cin >> odp;
                if (odp=="nie") {
                    int ind = PortfelFundusz.znajdz(nazwa);
                    if (czyEdytowac() == true) {
                        Fundusz fundusz;
                        dodajFundusz(fundusz,0);
                        PortfelFundusz.podstaw(fundusz,ind);
                    }
                } else if (odp=="tak") {
                    int ind = PortfelFunduszDywidenda.znajdz(nazwa);
                    if (czyEdytowac() == true) {
                        FunduszDywidenda fundusz;
                        dodajFundusz(fundusz,1);
                        PortfelFunduszDywidenda.podstaw(fundusz,ind);
                    }
                } else cout <<"Wprowadzono niepoprawna wartosc\n";
            } else if (typ=="kontrakt") {
                int ind = PortfelKontrakt.znajdz(nazwa);
                if (czyEdytowac()==true) {
                    Kontrakt nowa;
                    dodajKontrakt(nowa);
                    PortfelKontrakt.podstaw(nowa,ind);
                }
            } else if (typ=="nieruchomosc") {
                int ind = PortfelNieruchomosc.znajdz(nazwa);
                if (czyEdytowac()==true) {
                    Nieruchomosc nowa;
                    dodajNieruchomosc(nowa);
                    PortfelNieruchomosc.podstaw(nowa,ind);
                }
            } else if (typ=="IKE") {
                int ind = PortfelIKE.znajdz(nazwa);
                if (czyEdytowac()==true) {
                    IKE nowa;
                    dodajIKE(nowa);
                    PortfelIKE.podstaw(nowa,ind);
                }
            } else cout << "Wybrano niepoprawne aktywo\n";

        } else if (text=="/oszacuj") {
            double oszacowanie=0;
            string text;
            int czas;
            cout << "Podaj (w miesiacach) jaki okres czasu ma byc oszacowany: >> ";
            cin >> text;
            stringstream ss;
            ss << text;
            ss >> czas;
            if (czas == NULL || text.find('.') != -1) { cout <<"Niepoprawna wartosc\n";} else {
                oszacowanie+=PortfelLokata.oszacuj(czas);
                oszacowanie+=PortfelFundusz.oszacuj(czas);
                oszacowanie+=PortfelFunduszDywidenda.oszacuj(czas);
                oszacowanie+=PortfelKontrakt.oszacuj(czas);
                oszacowanie+=PortfelNieruchomosc.oszacuj(czas);
                oszacowanie+=PortfelIKE.oszacuj(czas);
                cout <<"Wynik szacowania:\n"<<oszacowanie<<"\n";
            }
        } else {
            cout << "Wybrano niepoprawna opcje\n";
        }
        save(PortfelLokata,PortfelFundusz,PortfelFunduszDywidenda,PortfelKontrakt,PortfelNieruchomosc,PortfelIKE);
    }






    return 0;
}
