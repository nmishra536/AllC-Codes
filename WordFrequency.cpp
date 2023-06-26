/************************************************************
Navya Mishra
nmishra3
PA 8
***********************************************************/

//-----------------------------------------------------------------------------
// Order.cpp
// Prints the lines of <input file> to <output file> in alphabetical order
// (with line numbers from <input file>), and then in pre-order (obtained
// by doing a pre-order tree walk.)
//
// To run this program, do
// 
//           Order <input file> <output file>
// 
//-----------------------------------------------------------------------------
#include<iostream>
#include<fstream>
#include <sstream>
#include <algorithm>
#include<string>
#include <cctype>
#include"Dictionary.h"

using namespace std;


/*WordFrequency.cpp is a program that reads in each line of a file, parse the individual words on each line,
 convert each word to all lower case characters, then places it (as key) in a Dictionary. Individual words in the 
 input file may be repeated, and the number of times a given word is encountered (its frequency) will also be 
 stored (as value) in the Dictionary. The program should parse the input file to remove all whitespace, 
 punctuation and special characters, then print the Dictionary to the output file.*/

int main(int argc, char * argv[]){

   // Make a dictionary "D";
   // Make an infile "in";
   // Make an outfile "out";
   string line;
   string token;
   int occurance = 1;
   //int line_num = 1;


   // open files for reading 
   ifstream input_file(argv[1]);

   
   // open files for writing
   ofstream output_file(argv[2]);
  

   // comment: read each line of input and place it in D 
  Dictionary D = Dictionary();
  //string line;
  //int count = 1
string res;
 string delim = " \t\\\"\',<.>/?;:[{]}|`~!@#$%^&*()-_=+0123456789";
 while (getline(input_file, line)) {
    transform(line.begin(), line.end(), line.begin(), ::tolower); // convert line to lowercase

    size_t pos = 0;
    while (pos < line.length()) {
        pos = line.find_first_not_of(delim, pos);
        if (pos == string::npos) break;

        size_t end = line.find_first_of(delim, pos);
        token = line.substr(pos, end - pos);

        // Add token to Dictionary
        if (D.contains(token)) {
            D.setValue(token, (D.getValue(token) + 1));
        } else {
            D.setValue(token, occurance);
        }

        pos = end;
    }
}
  /* while (getline(input_file, line)) {
        size_t len = line.length();
        size_t pos = line.find_first_of(delim);
        size_t start = line.find_first_not_of(delim);
        res = "";
        
        while(pos != string::npos || start != string::npos) {
            string token = line.substr(start, pos - start);
            
            // process token here
             res += token; 
            
            start = line.find_first_not_of(delim, 0);
            pos = line.find_first_of(delim, start);
        }
        string lower_str;
        for (char c : res) {
            lower_str += tolower(c);
        }
   // token = tolower(token);
        if ( D.contains(lower_str) == false){ //if its already in dictionary...

            D.setValue(lower_str, occurance);
    //line_num++;
        }else{ //if its not already in dictionary 
            int temp = D.getValue(lower_str);
             D.setValue(lower_str, (temp+1));
        }
    }*/

    output_file << D.to_string()<<endl;
   
   input_file.close();
   output_file.close();
   return(EXIT_SUCCESS);
}
