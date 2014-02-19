#include "node.h"

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include "prog4.h"

//constructor from initial word and lineNumber number
Node::Node(string newWord, int lineNumber){
	word = newWord;
	lineNumbers.push_back(lineNumber);
	left = NULL;
	right = NULL;
}

//default constructor
Node::Node(){
	word="";
	//lineNumbers = new vector<int>;
	left=NULL;
	right=NULL;
}

//destructor
Node::~Node(){
	//delete(word);
	lineNumbers.clear();
	delete(left);
	delete(right);
}

//print the words in the tree recursively
void Node::print(){
	//if(DEBUG){cout<<"Printing Node..."<<endl;}
	
	//print left side (lower)
	if (left){
		left->print();
	}
	
	//print this node
	cout << "Word: " << word << " Count: " << lineNumbers.size()<<" lines ";
	size_t count = lineNumbers.size();
	for(size_t i=0;i<count;i++){
		cout<< ' ' << lineNumbers[i];
	}
	cout<<endl;
	
	//print right side (higher)
	if(right){
		right->print();
	}
}


/*insert the given word and corresponding lineNumber number in to the tree
if the word is the same as this node, add it's lineNumber number to this node's numbers
otherwise find what branch (left or right) the word belongs on
if the branch exists, insert the word there (recursive)
if the branch does not exist, make a new leaf node for the word.
*/
void Node::insert(string insertedWord, int lineNumber){
		
	signed char comparison = (signed char)word.compare(insertedWord);
	if (comparison == 0){	//same word - increment this node
//		if(DEBUG){cout<<"\t'"<<insertedWord<<"' is a duplicate of this node - adding it's lineNumber number"<<endl;}
		lineNumbers.push_back(lineNumber);
		
	//different word - traverse one of the branches of this tree
	}else{
		
		//if this node is uninitialized
		if (lineNumbers.size()==0){
//			if(DEBUG){cout<<"Initializing this empty tree with "<<insertedWord<<" from line "<<lineNumber<<endl;}
			word=insertedWord;					//make ourselves match the new word
			lineNumbers.push_back(lineNumber);	//add the (only) line number
		
		//this node was initialized with a word and at-least one occurrence
		}else{
//			if(DEBUG){cout<<"This node "<<word<<" has "<<lineNumbers.size()<<" occurrences"<<endl;}
		
			//decide which branch to traverse (left, right) based on comparison
			Node** nextBranchPtrPtr=(comparison<0)? &left: &right;
			
			if (*nextBranchPtrPtr){	//if the branch exists
//				if(DEBUG){cout<<"Recursing on one of our branches..."<<endl;}
				(*nextBranchPtrPtr)->insert(insertedWord, lineNumber);	//recurs down the tree
			}else{	//if the branch doesn't exist
//				if(DEBUG){cout<<"Making a new leaf node here..."<<endl;}
				Node* newNodePtr = new Node(insertedWord, lineNumber);	//make a new node
				*nextBranchPtrPtr=newNodePtr;							//point our branch to it
			}
		}
	}
} //end insert function

