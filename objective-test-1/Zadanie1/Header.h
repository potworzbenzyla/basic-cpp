//
//  Header.h
//  Zadanie1
//
//  Created by Mateusz Mularski on 02/06/2022.
//

#ifndef Header_h
#define Header_h
using namespace std;

#endif /* Header_h */

class Uczen{
public:
   string imie, nazwisko, pesel;

    void podaj_imie(){
        cout<<"Podaj imie\n";
        cin>>imie;
    }
    
    void podaj_nazwisko(){
        cout<<"Podaj nazwisko\n";
        cin>>nazwisko;
    }
    
    void podaj_pesel(){
       cout<<"Podaj pesel\n";
        cin>>pesel;
   }
};

class Uczen_nazwa_szkoly :public Uczen{
public:
    string nazwa_szkoly;

   void podaj_szkole(){
       cout<<"Podaj nazwe szkoly\n";
       cin>>nazwa_szkoly;
   }
};

class Uczen_nazwa_klasy :public Uczen_nazwa_szkoly{
public:
    string klasa;

   void podaj_nazwe_klasy(){
       cout<<"Podaj klase\n";
       cin>>klasa;
   }
    void wyswietl_dane(){
        cout<<"Imie "<<imie<<endl;
        cout<<"Nazwisko "<<nazwisko<<endl;
        cout<<"Pesel "<<pesel<<endl;
        cout<<"Nazwa szkoly "<<nazwa_szkoly<<endl;
        cout<<"Nazwa klasy "<<klasa<<endl;
    }
};
