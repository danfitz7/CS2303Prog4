#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {

private:
	string word;
	int count;
	vector<int> lines;
	Node *leftNode;
	Node *rightNode;
	bool isNode;

public:
	Node(string newWord, int line);		//constructor prototype
	Node();		//default constructor prototype
	//~Node();	//destructor prototype
	
	void insert(string word, int line);
	string getWord() {return word;}
	void setValues(string newWord, int line);
	//void setValues(int line);
	void increaseValues(int line);
	void print();
	bool isEmpty() {return !isNode;}
};

#endif
