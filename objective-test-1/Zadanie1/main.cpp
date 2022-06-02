//
//  main.cpp
//  Zadanie1
//
//  Created by Mateusz Mularski on 02/06/2022.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main(){
    int czy_wyswietlic;
    Uczen_nazwa_klasy uczen;
    uczen.podaj_imie();
    uczen.podaj_nazwisko();
    uczen.podaj_pesel();
    uczen.podaj_szkole();
    uczen.podaj_nazwe_klasy();
    cout<<"Wpisz 1 aby wyswietlic dane"<<endl;
    cin>>czy_wyswietlic;
    
    if(czy_wyswietlic == 1){
        uczen.wyswietl_dane();
    }
    else{
        return 0;
    }
}
