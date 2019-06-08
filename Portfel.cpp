#include <iostream>
#include "Aktywo.hpp"
#include "Lokata.hpp"

using namespace std;

template <class Akt>
class Portfel {
private:
    int MAX;
    int current_size;
    Akt *tab;
public:
    Portfel(int a) {
        MAX = a;
        tab = new Akt[MAX];
        current_size = 0;
    };

    void operator+=(Akt cos) { //DODAJ
        int ind=0;
        while (tab[ind].getNazwa() != "")
            ind++;
        tab[ind] = cos;
        current_size++;
    };

    int operator-=(string nazwa) { //USUN
        int ind=0;
        while ( ( tab[ind].getNazwa() != nazwa ) & ( ind < MAX) )
            ind++;
        if (ind != MAX) {
            current_size--;
            Akt pusty;
            pusty.setNazwa("");
            cout << "Usunieto "<<tab[ind].getNazwa() << endl;
            tab[ind] = pusty;
            return 0;
        } else {
            cout <<"Wystapil blad: nie ma aktywa o takiej nazwie";
            return -1;
        }
    };

    int znajdz(string nazwa) {
        int ind=0;
        while ( ( tab[ind].getNazwa() != nazwa ) & ( ind < MAX) )
            ind++;
        tab[ind].info();
        return ind;
    };

    void podstaw(Akt nowa,int ind) {
        tab[ind]=nowa;
        cout << "Pomyslnie edytowano aktywo\n";
    };

    float oszacuj(int czas) {
        int ind=0;
        float wynik=0;
        while ( ( tab[ind].getNazwa() != "" ) & ( ind < MAX) ) {
            wynik+=tab[ind].ileZarobie(czas);
            ind++;
        }
        return wynik;
    };

    void wyswietl(string co) {
        int i=0;
        int ind=0;
        cout << "Twoje " <<co<<":\n";
        while( i < current_size) {
            if( tab[ind].getNazwa() != "") {
                i++;
                cout <<" "<<i<<". >> "<<tab[ind].getNazwa()<<endl;
            }
            ind++;
        } cout << endl;
    };

    Akt zKolei(int kolei) {
        int i=0;
        int ind=0;
        while(i < kolei) {
            if(tab[ind].getNazwa() != "")
                i++;
        ind++;
        }
        return tab[ind];
    }

    int getCurrentSize() {
        return current_size;
    }

};

