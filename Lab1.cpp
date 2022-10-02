/*
Navya Mishra
Summer 2022
Lab 1
Description of problem:
a few lines describing input, activity, and output of the program
The input is a string 25 characters or less. The code will then use a 
rot 13 cipher to encode or decode the input message and give it back.
Then, it will delete the message. 
*/


#include <iostream>
#include <string>
using namespace std;

//input function
void Message(string* pointer){
string message;
cout<<"Input string to be encoded/decoded: "<<endl;
cin.ignore();
getline(cin, message); //put this in later after i fix translation
//cin>>message;
*pointer = message;
}

//encrypt/decrypt
void Translate(string& message){
int index = 0;
string input = message;
int inputSize = (input.length());
while(index != inputSize)
        {
        if(input[index] >= 97 && input[index] <= 109)
            input[index] = input[index] + 13;
        else if(input[index] >= 110 && input[index] <= 122)
            input[index] = input[index] - 13;
        else if(input[index] >= 65 && input[index] <= 77)
            input[index] = input[index] + 13;
        else if(input[index] >= 78 && input[index] <= 90)
            input[index] = input[index] - 13;
        index++;
        }
        for (int i = 0; i < sizeof(input);i++){
            input[i] = input[i];
        }
        message = input;
}

//output
void PrintValue(string* pointer) {
   if (pointer == nullptr) {
      cout << "Pointer is null" << endl;
   }
   else {
      cout << "Your message is: "<< *pointer << endl;
   }
}

int main() {
    //input
    char ans2;
    do{
    cout<< "Do you want to decrypt/encrypt a message? (y/n)"<<endl;
    string answer;
    cin>> answer;
    if (answer == "y"){
    cin.ignore();
    string* message = new string[25];
    Message(message);
    Translate(*message);
    PrintValue(message);
    
    delete[] message;
    cout<< "Do you want to continue? (y/n)"<< endl;
    cin>>ans2;
    }
    }while (ans2 !='n');

    return 0;
}