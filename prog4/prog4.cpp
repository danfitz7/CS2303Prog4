/*
CS 2302 PROGRAM 4
Daniel Fitzgerald
Ethan Coeytaux
2/17/14
A Cross Reference Generator in C++
*/

#include "prog4.h"

//used for input and string manipulation
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <sstream>

//for atoi
#include <cstdlib>

//used for data structure
#include "node.h"

using namespace std;

//function prototypes
void testNodes();
void printVector(vector<int> vect);
void testVectors();
string toLowerCase(string strWord);

/*
This assignment requires creating a case-insensitive cross reference generator[1]. The program will take an 
ASCII text file as input (e.g. Lincoln’s Gettysburg Address). After reading in the file, the program prints out 
an alphabetized list of all the words in the file.
*/
int main(int argc, char* argv[]){
	if(DEBUG){cout<<endl<<endl<<"PROGRAM 3 "<<endl;}
	
	//ensure there is the correct number of command line arguments (the first is the name of our program, the second should be the number of arguments to come from a file)
	if (argc!=1){
		cout<<"ERROR: Proper usage has no command line arguments."<<endl;
		return 0;
	}
	
	//init an empty tree of words and their associated counts and line numbers
	Node tree;
		
	//loop through the input file until EOF
	string strInputLine;		//the current input line
	string strWord;				//the current word of each line	
	unsigned int lineNumber=0;	//the current line number
	while (getline(cin, strInputLine)){			//while we haven't reached the end of the file, keep reading in lines
		lineNumber++;			//increment line number count
		
		if(DEBUG){cout<<"Line "<<lineNumber<<" is: "<<strInputLine<<endl;}	//output the line for debugging
		
		istringstream iss(strInputLine);
		if(DEBUG){cout<<"\tWORDS:";}
		while (iss>>strWord){
			if(DEBUG){cout<<strWord<<"|";};
			
			//convert each word to lowercase so everything here-on-out is case-insensitive
			strWord=toLowerCase(strWord);
		
			//add the word and the line number to the tree
			tree.insert(strWord, lineNumber);
		}
		if(DEBUG){cout<<endl;}

	}
	
	cout<<"Done parsing file."<<endl;
	
	//print the final word cross reference
	tree.print();
		
	//testNodes();
	
	cout<<"\nDone."<<endl<<endl;
}

//helper function to make a string lowercase.
string toLowerCase(string strWord){
	for (size_t i=0;i<strWord.length();i++){
		strWord[i]=tolower(strWord[i]);
	}
	return strWord;
}

//helper function to test the tree data structure
void testNodes(){
	cout<<"Testing Nodes..."<<endl;
	
	Node testTree;
	cout<<"Node initialized..."<<endl;
	
	testTree.insert("Hello", 1);
	cout<<"Node 1 inserted..."<<endl;
	
	testTree.insert("world", 2);
	cout<<"Node 2 inserted..."<<endl;
	
	testTree.insert("apple", 3);
	cout<<"Node 2 inserted..."<<endl;
	
	cout<<"printing tree..."<<endl;
	testTree.print();
	
	cout<<"...Tree printed"<<endl;
}
