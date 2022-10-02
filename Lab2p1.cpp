/*
Navya Mishra
Summer 2022
Lab 2.1
Description of problem:
This code has a structure class to
organize airplane cargo data. The main
function creates a new container
to load data and then deletes the data when
finished, 

*/
#include <iostream>
#include <string>
using namespace std;

struct load{
    string uld;
    string abbreviation;
    string uldid;
    string aircraft;
    double weight ;
    string destination;
}


int main() {
  struct load* container= new struct load();
  input(container);
  output(container);
  delete container;
  container = nullptr;
   return 0;
}
void input(load* container ){
    string tempstr;
    int tempint;
    cout<<"Enter uld: "<<endl;
    cin>> tempstr;
    container.uld = tempstr;
    
    cout<<"Enter abbreviation: "<<endl;
    cin>> tempstr;
    container.abbreviation = tempstr;
    
    cout<<"Enter uldid: "<<endl;
    cin>> tempstr;
    container.uldid = tempstr;
    
    cout<<"Enter aircraft: "<<endl;
    cin>> tempstr;
    container.aircraft = tempstr;
    
    cout<<"Enter weight: "<<endl;
    cin>> tempint;
    container.weight = tempint;
    
    cout<<"Enter destination: "<<endl;
    cin>> tempstr;
    container.destination = tempstr;
    
}

void output(load* container){
   cout<< "uld: "<< container.uld<<endl;
   cout<< "abbreviation: "<< container.abbreviation<<endl;
   cout<< "uldid: "<< container.uldid<<endl;
   cout<< "aircraft: "<< container.aircraft<<endl;
   cout<< "weight: "<< container.weight<<endl;
   cout<< "destination: "<< container.destination<<endl;
}