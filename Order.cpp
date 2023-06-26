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
#include<string>
#include"Dictionary.h"

using namespace std;

int main(int argc, char * argv[]){

   // Make a dictionary "D";
   // Make an infile "in";
   // Make an outfile "out";
   string line;
   int line_num = 1;

   // check command line for correct number of arguments
    /*if (argc != 3) {
        cerr << "Usage: " << argv[0] << " arg1 arg2\n";
        return 1;
   }*/

   // open files for reading 
   ifstream input_file(argv[1]);

 /* if (!input_file) {
    cerr << "Could not open file: " << argv[1] << "\n";
    return 1;
  }*/

   
   // open files for writing
   ofstream output_file(argv[2]);

  /*if (!output_file) {
    cerr << "Could not open file: " << argv[2] << "\n";
    return 1;
  }*/
  

   // comment: read each line of input and place it in D 
  Dictionary D = Dictionary();
  //string line;
  //int count = 1
  while (getline(input_file, line)) {
    //int l = stoi(line);
    //string num = to_string(line_num);
    D.setValue(line, line_num);
    line_num++;
  }
   //iterate reading in each "line" from the input file:
      // in dictionary "D", set each "line number" as the value for each "line" as the key
      // increment the line number you are on for the next set of keys and values
   

   // print out the dictionary to the outfile
   //string s1;
   //D.to_string();
   //cout << "to_string" <<endl;
    output_file << D.to_string()<<endl;
   // cout << D.to_string()<<endl;
    // cout << endl;
   // print out the pre-order traversal of the tree to the outfile
   //string s;
   //D.pre_string(); //???????????? we dont have a function to return root????
    //cout << "pre_string" <<endl;
    output_file << D.pre_string()<<endl;
    //cout << D.pre_string()<<endl;
   //  cout << endl;
   // close files 
   input_file.close();
   output_file.close();
   return(EXIT_SUCCESS);
}
