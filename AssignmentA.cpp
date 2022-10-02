/* Navya Mishra
    CIS 22A Spring 2022
    Assignment A
    
    This program reads two numbers
    from the keyboard and prints 
    their product
*/
#include<iostream>

using namespace std;

int main (void)
  {
  double a;
  int b;
  double product;
  cout << "Enter a decimal number: ";
  cin >> a;
  cout << "Enter an integeral number: ";
  cin >> b;
   
  product = a*b;
  cout << a << "*" << b << " = " << product << endl;
  
  int temp;
  cout << "Enter an integer to close the output window: ";
  cin >> temp;
   
  return 0;
  }

  /* Execution results: 
Enter a decimal number: 3.14159
Enter an integeral number: 2
3.14159*2 = 6.28318
Enter an integer to close the output window: 4
  */