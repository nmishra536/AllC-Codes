/* Navya Mishra
    CIS 22A Spring 2022
    Assignment C1
    
    A program that asks the user 
    for a temperature in Celsius, 
    computes the corresponding 
    temperature in Fahrenheit, 
    and then prints the temperature 
    in Celsius and Fahrenheit.
*/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main (void)
{
  float Celsius;
  float Fahrenheit;
  const float ninefifths = 9/5;
  const int thirtytwo = 32;
  
  cout << "Enter Celsius: ";
  cin >> Celsius;
  Fahrenheit = (Celsius * ninefifths) + thirtytwo;
  
  
  cout << Celsius << endl;
  cout << setprecision(1) << fixed;
  cout << "Celcius: " << Celsius << endl;
  cout << "Fahrenheit: " << Fahrenheit << endl;
   
  return 0;
}

  /* Execution results: 
  Enter Celsius: 37.778
  37.778
  Celsius: 37.8
  Fahrenheit: 69.8
  */

 /* Execution results: 
 Enter Celsius: -40
  -40
  Celsius: -40.0
  Fahrenheit: -8.0
  */
  
  /* Execution results: 
  Enter Celsius: 0
  0
  Celsius: 0.0
  Fahrenheit: 32.0
  */