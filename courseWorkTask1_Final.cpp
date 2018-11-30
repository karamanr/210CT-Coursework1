#include "pch.h"
#include <iostream>

/*
Title: Binary Search Tree Implementation
Author: Hintea, D.
Date: 2017
Availability: http://moodle.coventry.ac.uk
*/

class BinTreeNode{
public:
	BinTreeNode(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
	int value;
	BinTreeNode* left;
	BinTreeNode* right;

};

BinTreeNode* tree_insert(BinTreeNode* tree, int item) {
	if (tree == NULL)
		tree = new BinTreeNode(item);
	else
		if (item < tree->value)
			if (tree->left == NULL)
				tree->left = new BinTreeNode(item);
			else
				tree_insert(tree->left, item);
		else
			if (tree->right == NULL)
				tree->right = new BinTreeNode(item);
			else
				tree_insert(tree->right, item);
	return tree;

}

void postorder(BinTreeNode* tree) {
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	std::cout << tree->value << std::endl;

}

void in_order(BinTreeNode* tree) {
	if (tree->left != NULL)
		in_order(tree->left);
	std::cout << tree->value << std::endl;
	if (tree->right != NULL)
		in_order(tree->right);
}


void deleteNodeFromBST(BinTreeNode* root_value, int key_value)
{
	BinTreeNode* selected_node = root_value;
	BinTreeNode* previously_selected_node = NULL;
	bool foundNode = false;

	// find the node we want to delete 

	while (foundNode == false)
	{
		if (selected_node == NULL)
		{
			return; 
		}

		else
		{
			if (selected_node->value == key_value)
			{
				foundNode = true; 
			}
			
			else
			{
				previously_selected_node = selected_node;
				if (key_value > selected_node->value)
					selected_node = selected_node->right;
				else
					selected_node = selected_node->left; 
			}
		}
	}

	if (foundNode == false)
	{
		return;
	}


	// if the node has no children, just delete it 

	if (selected_node->left == NULL && selected_node->right == NULL)
	{
		if (previously_selected_node->left == selected_node)
			previously_selected_node->left == NULL;
		else
			previously_selected_node->right = NULL;
		delete selected_node;
		return;
	}

	// if the node has one child to the left , we replace the node with the child

	else if (selected_node->left != NULL && selected_node->right == NULL)
	{
		if (previously_selected_node->left == selected_node)
		{
			previously_selected_node->left = selected_node->left;
			delete selected_node;
			selected_node = NULL;
			return;
		}
		else
		{
			previously_selected_node->right = selected_node->left;
			delete selected_node;
			selected_node = NULL;
			return;
		}
	}

	// if the node has one child to the right, we replace the node with the child

	else if (selected_node->right != NULL && selected_node->left == NULL)
	{
		if (previously_selected_node->right == selected_node)
		{
			previously_selected_node->right = selected_node->right;
			delete selected_node;
			selected_node = NULL;
			return;
		}
		else
		{
			previously_selected_node->left = selected_node->right;
			delete selected_node;
			selected_node = NULL;
			return; 
		}
	}

	//if the node we want to delete has two children, we find the max value in the left subtree and we replace it 

	else if (selected_node->left != NULL && selected_node->right != NULL)
	{
		BinTreeNode* maxLeftValue = selected_node->left;
		BinTreeNode* maxLeftValuePrev = selected_node; 


		while (maxLeftValue->right != NULL)
		{
			maxLeftValuePrev = maxLeftValue;
			maxLeftValue = maxLeftValue->right;
		}

		selected_node->value = maxLeftValue->value;

		if (maxLeftValue->left != NULL)
		{
			maxLeftValuePrev->right = maxLeftValue->left;
		}
		else
		{
			maxLeftValuePrev->right = NULL;
		}
		delete maxLeftValue;
		maxLeftValue = NULL;
		return; 
	}
}

int main(int argc, char *argv[])
{
	//BinTreeNode* t = tree_insert(0, 6);
	/*tree_insert(t, 10);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 3);
	tree_insert(t, 4);
	tree_insert(t, 11);*/
	BinTreeNode* t = tree_insert(0, 20);
	tree_insert(t, 15);
	tree_insert(t, 19);
	tree_insert(t, 11);
	tree_insert(t, 13);
	tree_insert(t, 9);
	tree_insert(t, 12);
	tree_insert(t, 5);
	tree_insert(t, 2);
	tree_insert(t, 3);


	deleteNodeFromBST(t, 16);
	deleteNodeFromBST(t, 19);
	deleteNodeFromBST(t, 13);
	




	in_order(t);
	return 0;
}
