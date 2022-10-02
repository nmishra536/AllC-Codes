/* Navya Mishra
    CIS 22A Spring 2022
    Assignment C2
    
    This program uses getline to read all 
    the characters input by the user, 
    and save these characters in a 
    string variable and then prints then
    string variable.
*/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main (void)
{
  string charvar;
  
  cout << "Enter name: ";
  getline(cin, charvar);
  
  
  cout << charvar << endl;
   
  return 0;
}

  /* Execution results: 
  Enter name: George Washington
  George Washington
  */
  
  /* Execution results: 
  Enter name: Franklin Delano Roosevelt
  Franklin Delano Roosevelt
  */
  