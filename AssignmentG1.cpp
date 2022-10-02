/* Navya Mishra
    CIS 22A Spring 2022
    Assignment G1
    
    This program reads a file
    named "file1" and returns
    the sum, min, max, avg, 
    and the number of numbers.
*/
#include<iostream>
#include<fstream>

using namespace std;

int main()

{
    ifstream myfile;
    myfile.open ("file1.txt");
    if (!myfile.is_open()){
        cout<<"File is not open"<<endl;
        
    }else{
        int count=0;
        int sum=0;
        int min=9999;
        int max=0;
        int x;
        
        while(myfile>>x){
            count++;
            sum+=x;
            if (max < x){
                max = x;
            }
            if (min > x){
                min = x;
            }
    
            
        }
        myfile.close();
        
        cout<<"The integer count: "<<count<<endl;
        cout<<"The sum of the integers: "<<sum<<endl;
        cout<<"The smallest integer: "<<min<<endl;
        cout<<"The largest integer: "<<max<<endl;
        cout<<"The average of the integers: "<<((sum*1.0)/count)<<endl;
        
    }
    return 0;
    
}
/*  Execution results: 
The integer count: 7
The sum of the integers: 141
The smallest integer: 9
The largest integer: 33
The average of the integers: 20.1429
*/

/*  Execution results: 
The integer count: 8
The sum of the integers: 181
The smallest integer: 9
The largest integer: 40
The average of the integers: 22.625
*/