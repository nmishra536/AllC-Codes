#include <iostream>

#include <iomanip>

using namespace std;

 

    int getSide(void){
        int side;
        cout<<"Enter square side: ";
        cin >> side;
        return side;
    }

    void computeArea(int side, int & area){
        area = side * side;
    }

 

    int main(void){
        int side =0;
        int area=0;
        side = getSide();
        computeArea(side, area);
        cout<< "Length of a Side: " << side<<endl;
        cout << "Square Area: " << area << endl;
        return 0;
    }
    