/* Navya Mishra
    CIS 22A Spring 2022
    Assignment G2
    
    This program creates a 
    pattern based on which 
    number the user chooses
    and then makes that pattern
    of whatever size the user
    inputs. 
*/
#include<iostream>

using namespace std;

int main(){

int i;
int j;
int k;
int size;
int sw;

do{

cout<<"Choose a pattern"<< endl;

cout<<"1. Square pattern"<< endl;

cout<<"2. Triangle pattern"<< endl;

cout<<"3. Diagonal pattern"<< endl;

cout<<"4. Reverse diagonal pattern"<<endl;

cout<<"5. Quit" << endl;

cin>>sw;

if (sw>0 && sw<= 5){

switch(sw){
    case 1:
    do{
    cout<<"Enter Size: ";
    cin>>size;
    if(!(size>=1 && size<=9)){
        cout<<"Input a size between 1 and 9."<<endl;
    }
}while(!(size>=1 && size<=9));
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){ 
            cout<<size; 
            
        }
        cout<<endl;
        
    }
    break;
    
    case 2:
    do{
    cout<<"Enter Size: ";
    cin>>size;
    if(!(size>=1 && size<=9)){
        cout<<"Input a size between 1 and 9."<<endl;
    }
}while(!(size>=1 && size<=9));
    for(i=0;i<size;i++){
        for(j=0;j<=i;j++){ 
            cout<<size; 
            
        }
       cout<< endl; 
    }
    break;
    
    case 3:
    do{
    cout<<"Enter Size: ";
    cin>>size;
    if(!(size>=1 && size<=9)){
        cout<<"Input a size between 1 and 9."<<endl;
    }
}while(!(size>=1 && size<=9));
    for(i=0;i<size;i++){
        for(j=0;j<i;j++){
            cout<<"*";
            
        }
        cout<<size;
        for(j=i+1;j<size;j++){
            cout<<"*";
            
        }
        cout<<endl;
        
    }
    break;
    
    case 4:
    do{
    cout<<"Enter Size: ";
    cin>>size;
    if(!(size>=1 && size<=9)){
        cout<<"Input a size between 1 and 9."<<endl;
    }
}while(!(size>=1 && size<=9));
    for(i=0;i<size;i++){
        for(j=1;j<size-i;j++){
            cout<<"*";
            
        }
        cout<<size;
        for(j=0;j<i;j++){
            cout<<"*";
            
        }
        cout<<endl;
        
    }
    break;
    
    case 5:
    return 0;
    break;
    
    default: 
    return 0;
    
}
}else{
    cout<< "Error: Choose a pattern from list"<<endl;
    
}
}while(sw!=5);
return 0;    
}
/* Execution Results:
Choose a pattern
1. Square pattern
2. Triangle pattern
3. Diagonal pattern
4. Reverse diagonal pattern
5. Quit
9
Error: Choose a pattern from list
Choose a pattern
1. Square pattern
2. Triangle pattern
3. Diagonal pattern
4. Reverse diagonal pattern
5. Quit
1
Enter Size: 11
Input a size between 1 and 9.
Enter Size: 3
333
333
333
Choose a pattern
1. Square pattern
2. Triangle pattern
3. Diagonal pattern
4. Reverse diagonal pattern
5. Quit
2
Enter Size: 4
4
44
444
4444
Choose a pattern
1. Square pattern
2. Triangle pattern
3. Diagonal pattern
4. Reverse diagonal pattern
5. Quit
3
Enter Size: 5
5****
*5***
**5**
***5*
****5
Choose a pattern
1. Square pattern
2. Triangle pattern
3. Diagonal pattern
4. Reverse diagonal pattern
5. Quit
4
Enter Size: 6
*****6
****6*
***6**
**6***
*6****
6*****
Choose a pattern
1. Square pattern
2. Triangle pattern
3. Diagonal pattern
4. Reverse diagonal pattern
5. Quit
5
*/

