#include<iostream>
#include<cstdlib>
#include<ctype.h>
using namespace std;

#define ERROR 1000000000
#define MAX 100

int tab[MAX], 
i = 0; 

bool push(int element){
  if(i>=MAX) return 0; 
  
  tab[i++] = element;
  return 1;
}

int pop(){
  if(i==0) return ERROR;
  
  --i;
  return 1; 
}

int size(){
  return i;
}

bool empty(){
  if(i==0) return 1;
  
  return 0; 
}


int value(){
  if(i==0) return ERROR;
  
  return tab[i-1];
}

int tabOutput(){
	cout<<"Oto cala kolejka: "<<endl;
	for(int j=0; j < size(); j++) cout<<tab[j]<<" ";
    cout<<tab[j]<<" ";
    cout<<"\n";
    return 0;
}

void cls()
    system("cls||clear");
    return;
}

void cnue(){ 
	string ch;
	cout<<"Wpisz cokolwiek aby kontynuowac ";
	cin>>ch;
}
	
int info(){
	cout<<"Liczba elementow na stosie: "<<size()<<endl;
    
    if(empty()){
    	cout<<"kolejka jest pusta"<<endl;
	}
	else{
		cout<<"Ostatnio dodany element na stosie : "<<value()<<endl;
	}
	
    cout<<"1.Dodaj element"<<endl;
    cout<<"2.Usun element"<<endl;
    cout<<"3.Wyswietl caly stos "<<endl;
}

int menu(){
    string m;
    cin>>m;
    
    if(m=="1"||"2"||"3"){
    	int menu = atoi(m.c_str());
    	switch (menu){
	        case 1:
	        	cls();
	        	int element;
	            cout<<"Wprowadz liczbe do kolejki:\n";
	            cin>>element;
	            push(element);
	            break;
	        case 2:
	        	cls();
	            if(pop()==ERROR){
	                cout<<"Kolejka jest pusta.\n";
	                cnue();
				}
	            break;
	        case 3:
	        	cls();
	            tabOutput();
	            cnue();
	            break;
		}
	}
	else{
		cout<<"Wprowadzono zle dane."<<endl;
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
