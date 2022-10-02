/* Navya Mishra
    CIS 22A Spring 2022
    Assignment F1
    
    This program reads two integers and
    if they are greater than or equal
    to 1 and less than or equal to 20 
    and the first int is smaller than
    or equal to the the second integer
    then it will print the int and the
    square root. 
*/

#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
    int int1;
    int int2;
    
    do {
        cout << "Enter an integer: ";
        cin >> int1;
        cout << "Enter an integer greater than to equal to the first integer: ";
        cin >> int2;
        if (!(int1 >= 1 && int1 <=20 && int2>=int1 && int2 >=1 && int2<=20 )){
            cout << "Integer 1 must be smaller than or equal to Integer 2 and both Integers must be greater than or equal to 1 and less than or equal to 20. " <<endl;
        }
    } while (!(int1 >= 1 && int1 <=20 && int2>=int1 && int2 >=1 && int2<=20 ));
    
    cout << "INTEGER" << setw(18) << "SQUARE ROOT" << endl;
    for (int i = int1; i <=int2; i++){
        cout << setprecision(4) << fixed;
        cout << setw (7) << i<< setw(18) << sqrt(i) <<endl;
    }
    return 0;
}

/* Execution Results:
Enter an integer: 2
Enter an integer greater than to equal to the first integer: 0
Integer 1 must be smaller than or equal to Integer 2 and both Integers must be greater than or equal to 1 and less than or equal to 20. 
Enter an integer: 2
Enter an integer greater than to equal to the first integer: 4
INTEGER       SQUARE ROOT
      2            1.4142
      3            1.7321
      4            2.0000
*/

/* Execution Results:
Enter an integer: 21
Enter an integer greater than to equal to the first integer: 5
Integer 1 must be smaller than or equal to Integer 2 and both Integers must be greater than or equal to 1 and less than or equal to 20. 
Enter an integer: 5
Enter an integer greater than to equal to the first integer: 5
INTEGER       SQUARE ROOT
      5            2.2361
*/