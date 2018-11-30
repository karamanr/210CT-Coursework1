
#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <fstream>

using namespace std;


// class for the vertices of the graph
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

	// add edges to the nodes , edited on 20/11/2018 to support weight for edges
	void addEdges(Vertex* node, int weight)
	{
		neighbours.insert({ node,weight });
	}

	// function to return the actual value so we don't get the pointer's value instead 
	int returnValue()
	{
		return value;
	}

	// function to print the adjacent nodes ( neighbours) 
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
				cout << "Printing neighbours..." << element.first->returnValue() << "(" << element.second << ")" << endl;
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
	// edited to support weights
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
		return NULL;
	}

	// dfs traversal for the graph
	void dfsTraversal(Graph* g, Vertex* n)
	{
		
		
		stack <Vertex*> stack;
		stack.push(n);
		while (!stack.empty())
		{

			if (stack.top()->checked == false)
			{
				
				cout << stack.top()->returnValue() << endl;
				
			}
				
			stack.top()->checked = true;
			Vertex* top = stack.top();
			stack.pop();
			for (auto elem : top->neighbours)
			{
				if (elem.first->checked == false)
				{
					stack.push(elem.first);
				}
			}
		}
		
	}

	// bfs traversal for the graph
	void bfsTraversal(Graph* g, Vertex* v)
	{
		queue<Vertex*> q;
		q.push(v);

		while (!q.empty())
		{
			if (q.front()->checked == false)
			{
				cout << q.front()->returnValue() << endl;
			}
			q.front()->checked = true;
			Vertex* front = q.front();
			q.pop();
			for ( auto elem : front->neighbours)
				if (elem.first->checked == false)
				{
					q.push(elem.first);
				}
		}
	}

	bool isPath(Vertex* n, Vertex* w)
	{

		ofstream myFile1("test1.txt");
		if (n == w)
			return true;
		queue<Vertex*> queue;
		queue.push(n);


		if (myFile1.is_open())
		{
			while (!queue.empty())
			{
				queue.front()->checked = true;
				Vertex* front = queue.front();
				queue.pop();
			

				if (front == w)
				{
					myFile1 << queue.front()->returnValue() << " " << endl;
					return true;
				}
				else
				{
					for (auto elem : front->neighbours)
					{
						if (elem.first->checked == false)
							queue.push(elem.first);
						myFile1 << queue.front()->returnValue() << " " << endl; 
					}
				}
			}
			return false;
		}

	 }

	bool isConnected(Graph* g)
	{

	}

	void dijkstra(Graph* g, Vertex* start, Vertex* destination)
	{
		if (isPath(start, destination) == false)
		{
			cout << "There is not path between these two nodes: " << start->returnValue() << "\n" << destination->returnValue() << endl;
			return;
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
	test->insertVertex(27);

	test->printGraph();


	test->addEdges(test->getNode(12), test->getNode(22), 3);
	test->addEdges(test->getNode(22), test->getNode(9), 2);
	test->addEdges(test->getNode(16), test->getNode(11), 5);
	test->addEdges(test->getNode(0), test->getNode(7), 2);
	test->addEdges(test->getNode(12), test->getNode(9), 1);
	test->addEdges(test->getNode(22), test->getNode(100), 3);
	test->returnEdges(test->getNode(16)); 

	
	// call the dfs function and then print the nodes that have been traversed to a text file
	cout << "dfs test:  " << endl;
	ofstream myFile2("test2.txt");

	if (myFile2.is_open())
	{
		for (int i = 0; i < test->verticesList.size(); i++)
		{
			test->dfsTraversal(test, test->verticesList[i]);
		
			myFile2 << test->verticesList[i]->returnValue();
			myFile2 << "\n";
			
		}
		cout << endl;
		myFile2.close();
	}

	
	ofstream myFile3("test.txt");

	if (myFile3.is_open())
	{
		for (int j = 0; j < test->verticesList.size(); j++)
		{
			test->bfsTraversal(test, test->verticesList[j]);
			myFile3 << test->verticesList[j]->returnValue();
			myFile3 << "\n";
		}
		myFile3.close();
	}
	


	for (int i = 0; i < test->verticesList.size(); i++)
	{
		test->verticesList[i]->checked = false;
	}
	if (test->isPath(test->getNode(12), test->getNode(22)))
	{
		cout << "There is a path between " << test->getNode(12)->returnValue() << " and " << test->getNode(22)->returnValue() << endl;
		
	}
	else if (test->isPath(test->getNode(12), test->getNode(100)) == false)
	{
		cout << "There is no path between nodes " << test->getNode(12)->returnValue()  << " and " << test->getNode(100)->returnValue()  << endl;
		
	}






}

