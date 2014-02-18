/*
CS 2302 PROGRAM 4
Daniel Fitzgerald
2/17/14
A Cross Reference Generator in C++
*/

#include "prog4.h"

//used for input and string manip
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>

#include <cstdlib>

//used for data structure
#include <vector>

using namespace std;

//function prototypes

/*
This assignment requires creating a case-insensitive cross reference generator[1]. The program will take an 
ASCII text file as input (e.g. Lincoln’s Gettysburg Address). After reading in the file, the program prints out 
an alphabetized list of all the words in the file.
*/
int main(int argc, char* argv[]){
	if(DEBUG){cout<<"PROGRAM 3 <<endl<< Processing "<<argc<<" events..."<<endl;}
	
	//ensure there is the correct number of command line arguments (the first is the name of our program, the second should be the number of arguments to come from a file)
	if (argc<2){
		cout<<"ERROR: Proper usage requires <source> and <event> followed by the event data, one event per line"<<endl;
		return 0;
	}
	
	//char* progString=argv[0];				//the first arg is always the name of the program
	unsigned int nLines=atoi(argv[1]); 		//the number of samples should be the second argument
	
	//loop through the rest of the command line arguments
	cout<<"Reading "<<nLines<<" lines of text..."<<endl;

	//variables to store input line data


	//loop through events to read in
	for (unsigned int arg=0;arg<nLines;arg++){	//loop through input lines
	}
	cout<<"\nDone.";
}
