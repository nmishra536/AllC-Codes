/* Navya Mishra
    CIS 22A Spring 2022
    Assignment I1
    
    This program has prototype functions
    which take inputs, add the inputs, 
    and print out the additions formatted.
*/

#include <iostream>

using namespace std;


/*
*************************************************************
The purpose of this function is to accept three integers from the user input.
The inputs are three ints from the user.
There is no output. The inputs are stored into first, second and third. 
*/
void getData(int &first, int &second, int &third){
	cout << "Enter first integer: ";
	cin >> first;
	cout << "Enter second integer: ";
	cin >> second;
	cout << "Enter third integer: ";
	cin >> third;
    }

/*
*************************************************************
The purpose of this function is to add all integers first, second, and third.
The inputs are integers first, second, and third.
The output is the sum of first, second, and third.  
*/
int ComputeTotal(int first, int second, int third){
	return first+second+ third;
    }

/*
*************************************************************
The purpose of this function is to print the sum of first, second, and third in a formatted way.
The inputs are integers first, second, and third.
The output is the sum of first, second, and third.  
*/
void printAll(int &first, int &second, int &third, int &total){
	cout << first << " + " << second << " + " << third << " = " << total;
    }

int main(){
	int first;
    int second;
    int third;
    int total;
	getData(first, second, third);
	total= ComputeTotal(first, second, third);
	printAll(first, second, third, total);
    }
    
    /* Execution resultes:
    Enter first integer: 4
Enter second integer: 5
Enter third integer: 6
4 + 5 + 6 = 15
    */