/* Navya Mishra
    CIS 22A Spring 2022
    Assignment D1
    
    This program calculates kinetic 
    energy and momentum given velocity
    and mass.
*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main (void)
{
    double m;
    double v;

    cout << "Enter mass: ";
    cin >> m;

    cout << "Enter velocity: ";
    cin >> v;

    double momentum;
    double kinetic;

    momentum = m * v;
    kinetic = (pow(v,2) * m ) / 2;

    cout << setprecision(2) << fixed;
    cout << "Input mass: " << setw(14) << m << "kg" << endl;
    cout << "Input velocity: " << setw(10) << v << "m/s" << endl;
    cout << "Output mass: " << setw(13) << m << "kg" << endl;
    cout << "Output velocity: " << setw(9) << v << "m/s" << endl; 
    cout << "Momentum: " << setw(16) << momentum << "kg * m /s" << endl;
    cout << "Kinetic Energy: " << setw(10) << kinetic << "J" << endl;

    return 0;
}

/* Execution results:
Enter mass: 5.0
Enter velocity: 4.0
Input mass:           5.00kg
Input velocity:       4.00m/s
Output mass:          5.00kg
Output velocity:      4.00m/s
Momentum:            20.00kg * m /s
Kinetic Energy:      40.00J

*/

/* Execution results:
Input mass:           3.15kg
Input velocity:      10.00m/s
Output mass:          3.15kg
Output velocity:     10.00m/s
Momentum:            31.50kg * m /s
Kinetic Energy:     157.50J

*/