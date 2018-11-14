// createGraphStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <fstream>




class Vertex
{
public:
	int current_value;
	std::map <Vertex*, int> neighbour_nodes;
	bool checked_node = false;
	int node_weight;

	Vertex(int next_value)
	{
		this->current_value = next_value; 
		this->neighbour_nodes = neighbour_nodes;
		this->checked_node = false;
	}
	

	void addNodeEdge(Vertex* node, int node_weight)
	{
		neighbour_nodes.insert({ node,node_weight });
	}

	int getValue()
	{
		return current_value;
	}

	void printNeighbourNodes()
	{
		if (neighbour_nodes.size() != NULL)
		{
			for (auto elem : neighbour_nodes)
			{
				std::cout << " --> " << elem.first->getValue() << "(" << elem.second << ") "; 
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Node is not connected! " << std::endl;
		}
	}

};

class Graph
{
public:
	std::vector<Vertex*> vertexList;
	
	Graph()
	{
		this->vertexList = vertexList;
	}

	void addVertex(int insert_into_node)
	{
		Vertex* node = new Vertex(insert_into_node);
		vertexList.push_back(node);
		std::cout << node->getValue() << " has been added to the list of vertices" << std::endl;
	}


	void addNodeEdges(Vertex* firstNode, Vertex* secondNode, int node_weight)
	{
		firstNode->addNodeEdge(secondNode, node_weight);
		secondNode->addNodeEdge(firstNode, node_weight);
		std::cout << firstNode->getValue() << " and " << secondNode->getValue() << " are now adjacent nodes!";
		std::cout << "\nThe edge of the weight is: " << node_weight << std::endl;
	}

	void showGraph()
	{
		std::cout << "Here is the list of vertices: " << std::endl;
		for (int i = 0; i < vertexList.size(); i++)
		{
			std::cout << vertexList[i]->getValue() << ", ";
		}
		std::cout << std::endl;
	}


	void showNodeEdges(Vertex* node)
	{
		std::cout << "The adjacent nodes of " << node->getValue() << " are: " << std::endl;
		node->printNeighbourNodes();
	}

	Vertex * getNode(int value)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->getValue() == value)
			{
				return vertexList[i];
			}
		}
		return NULL; 
	}

	bool isPath(Vertex* n, Vertex* v)
	{
		if (n == v)
			return true; 

		std::vector<Vertex*> vector;
		vector.push_back(n);

		while (!vector.empty())
		{

			vector.front()->checked_node = true;
			Vertex* front = vector.front();
			vector.pop_back();
			if (front == v)
			{
				return true;

			}
			else
			{

				for (auto elem : front->neighbour_nodes)
				{
					if (elem.first->checked_node == false)
						vector.push_back(elem.first);
					
					std::ofstream outFile("test_text_file.txt");
					for (const auto &e : vector) outFile << e << "\n";
				}
			}
		}
		

		return false;
	}


	
	
};
int main()
{
	Graph* new_graph = new Graph();
	new_graph->addVertex(10);
	new_graph->addVertex(29);
	new_graph->addVertex(5);
	new_graph->addVertex(12);
	new_graph->addVertex(16);
	new_graph->addVertex(15);

	new_graph->showGraph();


	new_graph->addNodeEdges(new_graph->getNode(10), new_graph->getNode(29), 3);
	new_graph->addNodeEdges(new_graph->getNode(5), new_graph->getNode(10), 2);
	new_graph->addNodeEdges(new_graph->getNode(5), new_graph->getNode(29), 5);

	new_graph->showNodeEdges(new_graph->getNode(15));

	new_graph->isPath(new_graph->getNode(10), new_graph->getNode(29));
}
