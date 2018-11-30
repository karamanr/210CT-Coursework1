#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node 
{ public:
	string data;
	Node* left;
	Node* right;
};

Node* GetNewNode(string data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// function to insert nodes into the tree
Node* Insert(Node* root_pointer, string data) {
	if (root_pointer == NULL) {
		root_pointer = GetNewNode(data);
		return root_pointer;
	}
	else if (data <= root_pointer->data) {
		root_pointer->left = Insert(root_pointer->left, data);
	}
	else {
		root_pointer->right = Insert(root_pointer->right, data);
	}
	return root_pointer;
}

// function to print the tree in preorder 
void pre_order(Node* root_pointer)
{
	if (!root_pointer)
	{
		return;
	}

	
	cout << root_pointer->data << " " << endl;
	pre_order(root_pointer->left);
	pre_order(root_pointer->right); 
}

// function to find if a word is in the tree
bool FindWord(Node* root, string data)
{
	if (root == NULL)
	{
		cout << "This word is not in the tree, sorry!" << endl;
		return false;
	}
	if (root->data == data)
	{
		cout << "This word is in the tree!" << endl;
		return true; 
	}
	if (root->data > data)
	{
		return FindWord(root->left, data);
	}
	return FindWord(root->right, data);
}

int main() {

	
	

	string word;
	ifstream inFile; // open the file
	Node* root_pointer = NULL; // Pointer to the root node

	inFile.open("example.txt");
	if (!inFile)     // make sure the file is open otherwise there might be an error
	{
		cout << "Unable to open text file";
	}

	while (inFile >> word) // loop to go through all the words in the text file
	{    
		root_pointer = Insert(root_pointer, word);
		if (word == "stop")
			break;
	}
	

	inFile.close();
	pre_order(root_pointer);
	FindWord(root_pointer, "");
}
