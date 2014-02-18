#include "node.h"

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

//constructor from initial word and line number
Node::Node(string newWord, int line){
	word = newWord;
	count = 1;
	lines.push_back(line);
	//leftNode = void;
	//rightNode = void;
	isNode = true;
}

//defualt constructor
Node::Node(){
	word="";
	count=0;
}

void Node::increaseValues(int line)
{
	count++;
	lines.push_back(line);
}

void Node::print()
{
	leftNode->print();
	cout << "Word: " << word << " Count: " << count;
	rightNode->print();
}

void Node::setValues(string setWord, int line){
	word=setWord;
	lines.clear();
	lines.push_back(line);
}

void Node::insert(string insertedWord, int line)
{
	if (isNode)
	{
		if (word.compare(insertedWord) == 0)
		{
			increaseValues(line);
		}
		else
		{
			Node newNode;
			newNode.setValues(insertedWord, line);
			if (word.compare(insertedWord) < -1) leftNode->insert(insertedWord, line);
			else rightNode->insert(insertedWord, line);
		}
	}
	else
	{
		setValues(insertedWord, line);
	}
	return;
} //end insert function

