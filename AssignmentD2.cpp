/* Navya Mishra
    CIS 22A Spring 2022
    Assignment D2
    
    This program calculates how much you
    owe given how many of what size boxes.
*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main (void)
{
    const double csmall = 9.20;
    const double cmedium = 8.52;
    const double clarge = 7.98;

    double small; 
    double medium;
    double large;

    cout << "How many boxes of small beads? ";
    cin >> small;

    cout << "How many boxes of medium beads? ";
    cin >> medium;

    cout << "How many boxes of large beads? ";
    cin >> large;

    double totalsmall;
    double totalmedium;
    double totallarge;
    double total;

    totalsmall = (csmall * small);
    totalmedium = (cmedium * medium);
    totallarge = (clarge * large);
    total = totalsmall + totalmedium + totallarge;

    cout << "SIZE" << setw(20) << "BOXES" << setw(18) << "COST PER BOX" << endl;
    cout << "Small " << setw(18) << small << setw(18);
    cout << setprecision(2) << fixed;
    cout << csmall << setw(10) << totalsmall << setw(7) << endl;
    cout << setprecision (0) << fixed;
    cout << "Medium " << setw(17) << medium << setw(18);
    cout << setprecision(2) << fixed;
    cout << cmedium << setw(10) << totalmedium << setw(6) << endl;
    cout << setprecision(0) << fixed;
    cout << "Large " << setw(18) << large << setw(18);
    cout << setprecision(2) << fixed;
    cout << clarge << setw(10) << totallarge<< setw(5) << endl;
    cout << "TOTAL" << setw(47) << total;

    return 0;
}

/* Execution results:
How many boxes of small beads? 9
How many boxes of medium beads? 8
How many boxes of large beads? 7
SIZE               BOXES      COST PER BOX
Small                  9              9.20     82.80
Medium                 8              8.52     68.16
Large                  7              7.98     55.86
TOTAL                                         206.82
*/