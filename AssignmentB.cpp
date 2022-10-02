/* Navya Mishra
    CIS 22A Spring 2022
    Assignment B1
    
    This program takes in a letter
    and then outputs the integer 
    and decimal forms of the input
    letter.
*/
#include<iostream>

using namespace std;

int main (void)
{
  char letter;
  int number;
  double decimalNumber;
  
  cout << "Enter a letter: ";
  cin >> letter;
  number = letter;
  decimalNumber = number;
  
  cout << "Character: " << letter << endl;
  cout << "Number: " << number << endl;
  cout << "Decimal number: " << decimalNumber << endl;
   
  return 0;
}

  /* Execution results: 
Enter a letter: a
Character: a
Number: 97
Decimal number: 97
  */
  
  /* Execution results: 
Enter a letter: A
Character: A
Number: 65
Decimal number: 65
  */