//
//  Header.h
//  Zadanie1
//
//  Created by Mateusz Mularski on 02/06/2022.
//

#ifndef Header_h
#define Header_h
#endif /* Header_h */

using namespace std;

class Zoo{
public:
    string gatunek, imie;

    void podaj_imie(){
        cout<<"Podaj imie. ";
        cin>>imie;
    }
};
    
class Eskulap :public Zoo{
public:
    string dlugosc;

   Eskulap(){
       gatunek = "Eskulap";
       podaj_imie();
       podaj_dlugosc();
       wyswietl_informacje();
   }
    
    void podaj_dlugosc(){
        cout<<"Podaj dlugosc. ";
        cin>>dlugosc;
    }
    void wyswietl_informacje(){
        cout<<"Gatunek "<<gatunek<<endl;
        cout<<"Imie "<<imie<<endl;
        cout<<"Dlugosc "<<dlugosc<<endl;
    }
};

class Panda :public Zoo{
public:
    string wysokosc, waga;

    Panda(){
       gatunek = "Panda";
        podaj_imie();
        podaj_wysokosc();
        podaj_wage();
        wyswietl_informacje();
   }
    
    void podaj_wysokosc(){
        cout<<"Podaj wysokosc ";
        cin>>wysokosc;
    }
    
    void podaj_wage(){
        cout<<"Podaj wage ";
        cin>>waga;
    }
    void wyswietl_informacje(){
        cout<<"Gatunek "<<gatunek<<endl;
        cout<<"Imie "<<imie<<endl;
        cout<<"Wysokosc "<<wysokosc<<endl;
        cout<<"Waga "<<waga<<endl;
    }
};

class Papuga :public Zoo{
public:
    string dlugosc, rozpietosc_skrzydel;

   Papuga(){
       gatunek = "Papuga ";
       podaj_imie();
       podaj_dlugosc();
       podaj_rozpietosc_skrzydel();
       wyswietl_informacje();
   }
    
    void podaj_dlugosc(){
        cout<<"Podaj dlugosc ";
        cin>>dlugosc;
    }
    
    void podaj_rozpietosc_skrzydel(){
        cout<<"Podaj rozpietosc skrzydel ";
        cin>>rozpietosc_skrzydel
        ;
    }
    
    void wyswietl_informacje(){
        cout<<"Gatunek "<<gatunek<<endl;
        cout<<"Imie "<<imie<<endl;
        cout<<"Dlugosc "<<dlugosc<<endl;
        cout<<"Rozpietosc_skrzydel "<<rozpietosc_skrzydel<<endl;
    }
};
