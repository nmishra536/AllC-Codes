/* Navya Mishra
    CIS 22A Spring 2022
    Assignment F2
    
    This program takes input for rolls
    and then input for price and then 
    prints out a table of rolls and 
    price per amount of rolls. 
*/
#include <iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
    int rolls;
    do {
        cout << "Enter maximum number of rolls of toilet paper: ";
        cin >> rolls;
    }while (!(rolls >= 1 && rolls <=10));
    double price;
    do {
        cout << "Enter price per roll: ";
        cin >> price;
    }while (!(price >= 0.10 && price <=3.00));
    
    cout << "ROLLS" << setw(18) << "PRICE" << endl;
    for (int i = 1; i<=rolls; i++ ){
        cout << setprecision(2) << fixed;
        cout << i<< setw(21) << (price * rolls) <<endl; 
    }
    return 0;
}

/* Execution Results:
Enter maximum number of rolls of toilet paper: 48
Enter maximum number of rolls of toilet paper: 4
Enter price per roll: 14.10
Enter price per roll: -2.70
Enter price per roll: 0.10
ROLLS             PRICE
1                 0.40
2                 0.40
3                 0.40
4                 0.40
*/