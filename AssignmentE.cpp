/* Navya Mishra
    CIS 22A Spring 2022
    Assignment E1
    
    This program calculates roots using the quadratic
    formula. 
*/
#include<iostream>
#include<cmath>

using namespace std;

int main (void)
{
double a;
double b;
double c;

float x = 0;
float determinant = 0;

cout << "Enter value for a: ";
cin >> a;
cout << "Enter value for b: ";
cin >> b;
cout << "Enter value for c: ";
cin >> c;

if (a == 0){
    if (b == 0){
        if (c == 0)
        cout << "Any value of x is a solution.";
        else{
        cout << "No solution exists.";
        }
        
    }else{
        x = (-c / b);
        cout << "x = " << x;
    }
        
    
    
    
}else{
    determinant = (pow(b, 2.0)) - (4 *a *c);
    if (determinant == 0){
        x = -b / (2*a);
        cout << "x = " << x;
    
        
    }else if (determinant < 0){
        cout << "The solutions have an imaginary component.";
        
    }else{
        cout << "x1 = " << (-b + sqrt(pow(b, 2.0) - 4*a*c )) / (2*a) << endl;
        cout << "x2 = " << ( -b - sqrt(pow(b, 2.0) - 4*a*c) ) / (2*a) << endl;
        
    }
}   

return 0;
    
}

/* Execution results:
Enter value for a: 0
Enter value for b: 0
Enter value for c: 0
Any value of x is a solution.
*/

/* Execution results:
Enter value for a: 0
Enter value for b: 0
Enter value for c: 4
No solution exists.
*/

/* Execution results:
Enter value for a: 0
Enter value for b: 8
Enter value for c: -12
x = 1.5
*/

/* Execution results:
Enter value for a: 2
Enter value for b: 4
Enter value for c: 2
x = -1
*/

/* Execution results:
Enter value for a: 2
Enter value for b: 2
Enter value for c: 0
x1 = 0
x2 = -1
*/

/* Execution results:
Enter value for a: 100
Enter value for b: 100
Enter value for c: -11
x1 = 0.1
x2 = -1.1
*/

/* Execution results:
Enter value for a: 1
Enter value for b: 1
Enter value for c: 1
The solutions have an imaginary component.
*/