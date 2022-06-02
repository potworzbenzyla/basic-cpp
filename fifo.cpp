#include <iostream>
#include <cstdlib>
#include <ctype.h>
using namespace std;

#define MAX 100 
#define ERROR 1000000000

int tab[MAX], p = 0, k = 0;

int push(int element){
    if(k==MAX)
        return 0;
    
    tab[k++] = element;
    return 1;
}

int pop()
{
    if(p==k)
        return 0;
    
    ++p;
    return 1;
}

int size(){
    return k-p;
}

int first(){
    if(p==k)
        return ERROR;
        
    return tab[p];
}

int last(){
    if(p==k)
        return ERROR;
        
    return tab[k-1];
}

int tabOutput(){
	cout<<"Oto cala kolejka: "<<endl;
	for(int j=0; j < size(); j++) cout<<tab[j]<<" ";
    cout<<tab[j]<<" ";
    cout<<"\n";
    return 0;
}

void cls(void) //czysci ekran
{
    system("cls||clear");
    return;
}

void cnue(void){ 
	string ch;
	cout<<"Wpisz cokolwiek aby kontynuowac ";
	cin>>ch;
}

int info(){ //wyswietla informacje uzytkownikowi
	cout<<"Liczba elementow w kolejce: "<<size()<<endl;
    
    if(last()==1000000000){
    	cout<<"Kolejka jest pusta"<<endl;
	}
	else{
		    cout<<"Pierwszy element w kolejce: "<<first()<<endl;
	}
	
    cout<<"1.Dodaj elementy do kolejki"<<endl;
    cout<<"2.Usun elementy z kolejki"<<endl;
    cout<<"3.Wyswietl cala kolejke"<<endl;
}

int menu(){
    string m;
    cin>>m;
    
    if(m=="1"||"2"||"3"){
    	int menu = atoi(m.c_str());
	    switch(menu){
	        case 1:
	        	int element;
	        	cls();
	            cout<<"Wprowadz liczbe do stosu: \n";
	            cin>>element;
	            if(!push(element)){
	            	cout<<"Kolejka przepelniona\n";
	           		cnue();
	           }
	            break;
	    
	        case 2:
	        	cls();
	            if(!pop()){
	                cout<<"Kolejka jest juz pusta.\n";
	                cnue();
	            }
	            break;
	            
	        case 3:
	        	cls();
	            if(size() == 0){
	                cout<<"Kolejka jest pusta.\n";
	                cnue();
	            }
	            else{
	                tabOutput();
	                cnue();
	            }
	            break;
	    }
	}
    return 0;
}

int main(){
    for(;;){
    	cls();
    	info();
        menu();
    }
    return 0;
}
