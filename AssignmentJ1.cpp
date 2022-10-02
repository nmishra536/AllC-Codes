/* Navya Mishra
    CIS 22A Spring 2022
    Assignment J1
    
    This program prints out the sum
    of an array formatted.
*/
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main (void){
    int arr[] = { 4, 6, 9, 12};
    int total = 0;
    int v = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < 4; i++) {
        total += arr[i];
        }
    for (int i = 0; i < 4; i++) {
        if (arr[i] != arr[v-1]){
            cout << arr[i] << " + ";
            }
        }
    cout<< arr[v-1] << " = " << total;
    return 0;
}

/* Execution results:
4 + 6 + 9 + 12 = 31
*/

