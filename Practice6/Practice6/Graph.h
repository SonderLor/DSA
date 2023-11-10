#ifndef GRAPH_H


#include <iostream>
#include <set>
#include <map>
#include <vector>


class Edge;


struct Node {
	int value;
	std::set<Edge*> edges;
	std::map<Node*, Edge*> parents;
	Node();
	Node(int value);
};


class Edge {
public:
	Node* adjacentNode;
	int weight;
	Edge(Node* adjacentNode, int weight);
};


Node* addOrGetNode(std::map<int, Node*>& graph, int value);
std::map<int, Node*> createGraph(std::vector<std::vector<int>> graphData);


#endif