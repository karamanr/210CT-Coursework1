// question3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

class Vertex
{
public:
	int value;
	map <Vertex*, int> neighbours;
	bool checked = false;
	int weight;

	Vertex(int value)
	{
		this->value = value;
		this->neighbours = neighbours;
		this->checked = false;
	}

	void addEdges(Vertex* node, int weight)
	{
		neighbours.insert({ node,weight });
	}

	int returnValue()
	{
		return value;
	}

	void printNeightbours()
	{
		if (neighbours.size() == NULL)
		{
			cout << "Sorry, but this appears to be empty! ( node is disconnected) " << endl;
		}
		else
		{
			for (auto element : neighbours)
			{
				cout << "Elements: " << element.first->returnValue() << "(" << element.second << ")" << endl;
			}
		}
	}

};


class Graph
{
public:
	vector <Vertex*> verticesList;
	Graph()
	{
		this->verticesList = verticesList; 
	}

	void insertVertex(int data)
	{
		Vertex* node = new Vertex(data);
		verticesList.push_back(node);
		cout << node->returnValue() << " has been added!" << endl;
	}

	void addEdges(Vertex* nodeOne, Vertex* nodeTwo, int weight)
	{
		nodeOne->addEdges(nodeTwo, weight);
		nodeTwo->addEdges(nodeOne, weight);

		cout << "Nodes " << nodeOne->returnValue() << " and " << nodeTwo->returnValue() << " are now adjacent to each other! " << endl;
		cout << "The weight of the edge for these two nodes is: " << weight << endl;
	}

	void printGraph()
	{
		cout << "\nThe vertices in this graph are: " << endl;
		for (int i = 0; i < verticesList.size(); i++)
		{
			cout << verticesList[i]->returnValue() << endl; 
		}
	}

	void returnEdges(Vertex* node)
	{
		cout << node->returnValue() << " has the current adjacent nodes: " << endl;
		node->printNeightbours();
	}

	Vertex* getNode(int val)
	{
		for (int i = 0; i < verticesList.size(); i++)
		{
			if (verticesList[i]->returnValue() == val)
			{
				return verticesList[i];
			}
		}
	}


};

int main()
{
	Graph* test = new Graph();
	test->insertVertex(12);
	test->insertVertex(22);
	test->insertVertex(9);
	test->insertVertex(0);
	test->insertVertex(5);
	test->insertVertex(11);
	test->insertVertex(7);
	test->insertVertex(16);
	test->insertVertex(100);

	test->printGraph();


	test->addEdges(test->getNode(12), test->getNode(22), 3);
	test->addEdges(test->getNode(22), test->getNode(9), 2);
	test->addEdges(test->getNode(16), test->getNode(11), 5);
	test->addEdges(test->getNode(0), test->getNode(7), 2);
	test->addEdges(test->getNode(12), test->getNode(9), 1);
	test->addEdges(test->getNode(22), test->getNode(100), 3);
	test->returnEdges(test->getNode(22)); 

}

