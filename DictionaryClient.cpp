//-----------------------------------------------------------------------------
// DictionaryClient.cpp
// A test client for the Dictionary ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"Dictionary.h"

using namespace std;

int main(){

   string s;
   int x;
   string S[] =   {
                     "plaices",
                     "ambusher",
                     "crosby",
                     "wattles",
                     "pardoner",
                     "pythons",
                     "second",
                     "forms",
                     "impales",
                     "pic",
                     "verticals",
                     "recriminator",
                     "depressants",
                     "cul",
                     "potables",
                     "norm",
                     "reinsurer",
                     "deschooler",
                     "recoining",
                     "dissocialised",
                     "cohabit",
                     "hemiolia",
                     "cantling",
                     "glamorized",
                     "millesimal",
                     "glagolitic"
                  };
   string T[] =   {
                     "second",
                     "forms",
                     "impales",
                     "pic",
                     "verticals",
                     "recriminator",
                     "depressants",
                     "cul",
                     "potables",
                     "norm",
                     "reinsurer",
                     "deschooler",
                     "recoining",      
                  };
   cout<< "error1" <<endl;
   Dictionary A;
   cout<< "error2" <<endl;
   Dictionary B;
   cout<< "error3" <<endl;

   cout << endl;

   // insert some pairs into A
   for(int i=0; i<26; i++){
      A.setValue(S[i], i+1);
   }
   cout<< "dictionary a :\n "<<A <<endl;
   cout<< "dictionary a size : "<<A.size() <<endl;
   cout<< "error4" <<endl;
   // call operator=()
   B = A;
   cout<< "error5" <<endl;

   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout<< "error6" <<endl;
   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout<< "error7" <<endl;

   B.setValue("deschooler", 101);
   cout<< "error8" <<endl;
   B.setValue("reinsurer", 102);
   cout<< "error9" <<endl;
   B.setValue("glagolitic", 103);
   cout<< "error10" <<endl;
   B.setValue("cul", 104);
   cout<< "error11" <<endl;
   B.setValue("ambusher", 105);
   cout<< "error12" <<endl;

   // call copy constructor
   Dictionary C = B;

   cout << "B.size() = " << B.size() << endl  << B << endl;
   cout << "C.size() = " << C.size() << endl  << C << endl;

   // check operator==()
   cout << "A==B is " << (A==B?"true":"false") << endl;
   cout << "B==C is " << (B==C?"true":"false") << endl;
   cout << "C==A is " << (C==A?"true":"false") << endl << endl;

   // perform alterations on A
   cout << A.getValue("hemiolia") << endl;
   A.getValue("hemiolia") *= 10; // change the value associated with "hemiolia"
   cout << A.getValue("hemiolia") << endl << endl;

   // check state of A
   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << A.pre_string() << endl;

   // remove some pairs from A
   for(int i=0; i<13; i++){
      cout << "removing " << T[i] << " from Dictionary A" << endl; 
      A.remove(T[i]);
   }

   cout << "after remove loop" << endl;

   // check state of A
   cout << "A.size() = " << A.size() << endl  << A << endl;
   cout << A.pre_string() << endl;
   
   cout << "error 1"<<endl;
   // do forward iteration on A
   for(A.begin(); A.hasCurrent(); A.next()){
      s = A.currentKey();
      x = A.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;
   cout << "error 2"<<endl;
   A.end();
   cout << "error 3"<<endl;
   A.prev();
   cout << "error 4"<<endl;
   // do reverse iteration on A
   for(A.end(); A.hasCurrent(); A.prev()){
      s = A.currentKey();
      x = A.currentVal();
      cout << "("+s+", " << x << ") ";
   }
   cout << endl << endl;
   cout << "error 5"<<endl;
   // check exceptions
   try{
      A.getValue("blah");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.remove("blah");
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentKey();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.currentVal();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }  
   try{
      A.next();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      A.prev();
   }catch(logic_error& e){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }

   cout << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  
   cout <<"done" << endl;  

   return( EXIT_SUCCESS );
}
