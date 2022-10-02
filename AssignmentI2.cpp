/* Navya Mishra
    CIS 22A Spring 2022
    Assignment I2
    
    This program has prototype functions
    which take inputs, add the inputs, 
    and print out the additions formatted.
*/
#include <iostream>

using namespace std;


/*
*************************************************************
The purpose of this function is to accept four integers and two doubles from the user input.
The inputs are four ints and two doubles from the user.
There is no output. The inputs are stored into first, second, third, fourth, decimalOne and decimalTwo. 
*/
void getData(int& first,int& second,int& third,int& fourth,double& decimalOne,double& decimalTwo){
	cout<<"Enter first: ";
	cin>>first;
	cout<<"Enter fourth: ";
	cin>>second;
	cout<<"Enter third: ";
	cin>>third;
	cout<<"Enter fourth: ";
	cin>>fourth;
	cout<<"Enter decimalOne: ";
	cin>>decimalOne;
	cout<<"Enter decimalTwo: ";
	cin>>decimalTwo;
}

/*
*************************************************************
The purpose of this function is to add integers first and second.
The inputs are integers first and second.
The output is the sum of first and second.  
*/
int computeTotal(int first,int second){
	return first+second;
}

/*
*************************************************************
The purpose of this function is to add integers first, second, and third.
The inputs are integers first, second, and third.
The output is the sum of first, second, and third.  
*/
int computeTotal(int first,int second,int third){
	return first+second+third;
}


/*
*************************************************************
The purpose of this function is to add integers first, second, third and fourth.
The inputs are integers first, second, third, and fourth.
The output is the sum of first, second, third and fourth.  
*/
int computeTotal(int first,int second,int third,int fourth){
	return first+second+third+fourth;
}

/*
*************************************************************
The purpose of this function is to add all doubles decimalOne and decimalTwo.
The inputs are integers decimalOne and decimalTwo.
The output is the sum of decimalOne and decimalTwo.  
*/
double computeTotal(double decimalOne,double decimalTwo){
	return decimalOne+decimalTwo;
}

/*
*************************************************************
The purpose of this function is to print the sum of first and second in a formatted way.
The inputs are integers first and second.
The output is the sum of first and second.  
*/
void printAll(int first,int second,int total){
	cout << first << " + " << second << " = " << total;
}

/*
*************************************************************
The purpose of this function is to print the sum of first, second, and third in a formatted way.
The inputs are integers first, second, and third.
The output is the sum of first, second, and third.  
*/
void printAll(int first,int second,int third,int total){
	cout << first << " + " << second << " + " << third << " = " << total;
}

/*
*************************************************************
The purpose of this function is to print the sum of first, second, third, and fourth in a formatted way.
The inputs are integers first, second, third, and fourth.
The output is the sum of first, second, third, and fourth.  
*/
void printAll(int first,int second,int third,int fourth,int total){
	cout << first << " + " << second << " + " << third << " + "<< fourth<<" = " << total;
}

/*
*************************************************************
The purpose of this function is to print the sum of decimalOne and decimalTwo in a formatted way.
The inputs are doubles decimalOne and decimalTwo.
The output is the sum of decimalOne and decimalTwo.  
*/
void printAll(double decimalOne,double decimalTwo,double decimalTotal){
	cout << decimalOne << " + " << decimalTwo <<" = " << decimalTotal;
}

int main() {
	int first;
    int second;
    int third;
    int fourth;
    int total;
	double decimalOne;
    double decimalTwo;
    double decimalTotal;
	getData(first,second,third,fourth,decimalOne,decimalTwo);


	cout<<"First and second: "<<computeTotal(first,second)<<endl;
	cout<<"First, second and third: "<<computeTotal(first,second,third)<<endl;
	cout<<"First, second, third and fourth: "<<computeTotal(first,second,third,fourth)<<endl;
	cout<<"decimalOne and decimalTwo: "<<computeTotal(decimalOne,decimalTwo)<<endl;
	cout << "For integers: " << endl;
	total = computeTotal(first,second,third,fourth);
	decimalTotal = computeTotal(decimalOne,decimalTwo);
	printAll(first,second,third,fourth, total);
	cout << endl <<"For decimal numbers: " << endl;
	printAll(decimalOne, decimalTwo, decimalTotal);
	return 0;
}

/* Execution results:
Enter first: 4
Enter fourth: 5
Enter third: 6
Enter fourth: 7
Enter decimalOne: 8.1234
Enter decimalTwo: 9.5678
First and second: 9
First, second and third: 15
First, second, third and fourth: 22
decimalOne and decimalTwo: 17.6912
For integers: 
4 + 5 + 6 + 7 = 22
For decimal numbers: 
8.1234 + 9.5678 = 17.6912
*/