/* Navya Mishra
    CIS 22A Spring 2022
    Assignment H2
    
    This program contains three
	prototype functions that find
	the sum of three numbers, 
	find the average of numbers 
	given how many and find the 
	smallest of three numbers.
*/
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;



/*
*************************************************************
The purpose of this function is to add three floats.
The inputs are three floats num1, num2 and num3.
The output is the float sum of num1, num2 and num3.
*/
float findSum(float num1,float num2,float num3){
	return (num1+num2+num3);
}

/*
*************************************************************
The purpose of this function is to find the average given the sum and total number of floats.
The inputs are two floats, the sum of the float numbers, and the amount of numbers that made the sum.
The output is the float average given by division of the sum and the number of numbers.
*/
float findAverage(float sum,float num){
	return (sum/num);
}

/*
*************************************************************
The purpose of this function is find the smallest number given three numbers
The inputs are three floats num1, num2 and num3.
The output is one of floats num1, num2, or num3; whichever is smallest.
*/
float findSmallest(float num1,float num2,float num3){
	if (num2 < num1 && num2 < num3){
		return num2;
	}
	if (num1 < num2 && num1 < num3){
		return num1;
	}else{
	return num3;
	}
}


int main() {


	float num1;
	float num2;
	float num3;


	cout<<"Enter a number: ";
	cin>>num1;
	cout<<"Enter second number: ";
	cin>>num2;
	cout<<"Enter third number: ";
	cin>>num3;
	
	cout << setprecision(2) << fixed;
	cout<<"First number" <<setw(11)<<num1<<endl;
	cout<<"Second number"<<setw(10) <<num2<<endl;
	cout<<"Third number"<<setw(11) <<num3<<endl;

	cout<<"Total"<<setw(18) <<findSum(num1,num2,num3)<<endl;
	cout<<"Average"<<setw(16) <<findAverage(findSum(num1,num2,num3),3)<<endl;
	cout<<"Smallest"<<setw(15) <<findSmallest(num1,num2,num3)<<endl;



	return 0;
}

/* Execution results:
Enter a number: 37.144
Enter second number: 2.4144
Enter third number: 19
First number      37.14
Second number      2.41
Third number      19.00
Total             58.56
Average           19.52
Smallest           2.41
*/

/* Execution results:
Enter a number: 4.23
Enter second number: 5.78
Enter third number: 6.21
First number       4.23
Second number      5.78
Third number       6.21
Total             16.22
Average            5.41
Smallest           4.23
*/