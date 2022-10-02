/* Navya Mishra
    CIS 22A Spring 2022
    Assignment C3
    
    This program takes in a 
    first and last name on 
    one line and then prints
    the initials.
*/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main (void)
{
  char firsti;
  string firstn;
  char lasti;
  string lastn;
  
  cout << "Enter first name and last name: ";
  cin >> firstn >> lastn;
  firsti = firstn[0];
  lasti = lastn[0];
  
  
  
  cout << firsti << lasti << endl;
   
  return 0;
}

  /* Execution results: 
  Enter first name and last name: Harry Truman
  HT
  */
  