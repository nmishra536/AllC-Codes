/* Navya Mishra
    CIS 22A Spring 2022
    Assignment H1
    
    This program contains
    a prototype function
    that adds two integers.
*/

#include <iostream>

using namespace std;

/*
*************************************************************
The purpose of this function is to add two integers.
The inputs are two integers a and b.
The output is the integer sum of a and b.
*/
 int sum(int a, int b){
	return (a + b);
	}

int main(){
	int int1;
	int int2;
	cout << "Enter an integer: ";
	cin >> int1;
	cout << "Enter another integer: ";
	cin >> int2;
	cout << "int1: " << int1 <<endl;
	cout << "int2: " << int2<<endl;
	cout << "Sum:  "<<sum(int1, int2)<<endl;

}
/* Execution results:
Enter an integer: 3
Enter another integer: 4
int1: 3
int2: 4
Sum:  7
*/

/* Execution results: 
Enter an integer: 5
Enter another integer: 49
int1: 5
int2: 49
Sum:  54
*/