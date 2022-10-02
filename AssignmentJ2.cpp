/* Navya Mishra
    CIS 22A Spring 2022
    Assignment J2
    
    This program takes an array from user input
    and prints the sum of that array in format.
*/
#include <iostream>
using namespace std;


const int N=4;
/*
*************************************************************
The purpose of this function is to get a 4 integer array from user input.
The inputs are numbers the user will type.
There is no output. The integers are stored in the array.
*/

void getData(int a[N]) {
    for (int i=0; i<N; i++) {
        cout << "Enter integer: ";
        cin >> a[i];
    }
}


/*
*************************************************************
The purpose of this function is to add all the integers in the array.
The input is the array.
The output is the integer sum of all the integers in the array.
*/
int computeTotal(int a[N]) {
    int tot = 0;
    for (int i=0; i<N; i++) {
        tot += a[i];
    }
    return tot;
}

/*
*************************************************************
The purpose of this function is to format and print the numbers of the array and the sum of that array.
The inputs are an array and the int total of the array.
The output is the sum of the array in format.
*/

void printAll(int a[N], int tot) {
    cout << a[0];
    for (int i=1; i<N; i++) {
        cout << " + " << a[i];
    }
    cout << " = " << tot << endl;
}


int main() {
    int a[N];
    int sum;


    getData(a);
    sum = computeTotal(a);
    printAll(a, sum);


    return 0;
}

/* Execution results:
Enter integer: 4
Enter integer: 6
Enter integer: 9
Enter integer: 12
4 + 6 + 9 + 12 = 31
*/

/* Execution results:
Enter integer: 1
Enter integer: 7
Enter integer: 9
Enter integer: 15
1 + 7 + 9 + 15 = 32
*/