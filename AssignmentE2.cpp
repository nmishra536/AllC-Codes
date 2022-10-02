/* Navya Mishra
    CIS 22A Spring 2022
    Assignment E2
    
    This program determines the letter grade from 
    the average of 3 test scores and possibly homework.
*/
#include<iostream>
#include<iomanip>

using namespace std;

int main (void)
{
    const int A = 90;
    const int B = 80;
    const int C = 70;
    const int D = 60;
    const int MAX = 100;
    
    int score1, score2, score3;
    double average;
    cout << "Enter score 1: ";
    cin >> score1;
    cout << "Enter score 2: ";
    cin >> score2;
    cout << "Enter score 3: ";
    cin >> score3;
    
    average = (score1 + score2 + score3) /3.0;
    cout << "Grade average: " << average << endl;
    if (average <= MAX){
        if (average >= A){
            cout << "Grade: A" << endl;
        }else if (average >= B){
            cout << "Grade: B" << endl;
        }else if (average >= C){
            cout << "Grade: C" << endl;
        }else if (average >= D){
            cout << "Enter amount of assignments turned in: ";
            int hw;
            int totalhw;
            cin >> hw;
            cout << "Enter amount of total homeworks: ";
            cin >> totalhw;
            if ((hw*100/totalhw) > B){
                cout << "Grade: D" << endl;
            }else{
                cout << "Grade: F" << endl;
            }
            
        }else{
            cout << "Grade: F" << endl;
        }
        
    }else{
        cout << "Test scores are over the maximum value." << endl;
    }

    
return 0;
}
/* Execution results:
Enter score 1: 96
Enter score 2: 84
Enter score 3: 90
Grade average: 90
Grade: A
*/

/* Execution results:
Enter score 1: 95
Enter score 2: 83
Enter score 3: 90
Grade average: 89.3333
Grade: B
*/

/* Execution results:
Enter score 1: 70
Enter score 2: 59
Enter score 3: 60
Grade average: 63
Enter amount of assignments turned in: 5
Enter amount of total homeworks: 6
Grade: D
*/

/* Execution results:
Enter score 1: 73
Enter score 2: 58
Enter score 3: 65
Grade average: 65.3333
Enter amount of assignments turned in: 8
Enter amount of total homeworks: 11
Grade: F
*/