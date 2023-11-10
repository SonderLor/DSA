#include "Graph.h"

Node::Node() {
	value = -1;
}

Node::Node(int value) {
	this->value = value;
}


Edge::Edge(Node* adjacentNode, int weight) {
	this->adjacentNode = adjacentNode;
	this->weight = weight;
}


Node* addOrGetNode(std::map<int, Node*>& graph, int value) {
	if (value == -1) {
		return nullptr;
	}
	if (graph.find(value) != graph.end()) {
		return graph.find(value)->second;
	}
	Node* node = new Node(value);
	graph.insert(std::make_pair(value, node));
	return node;
}


std::map<int, Node*> createGraph(std::vector<std::vector<int>> graphData) {
	std::map<int, Node*> graph;
	for (int i = 0; i < graphData.size(); i++) {
		Node* node = addOrGetNode(graph, graphData[i][0]);
		Node* adjacentNode = addOrGetNode(graph, graphData[i][1]);
		if (adjacentNode == nullptr) {
			continue;
		}
		Edge* edge = new Edge(adjacentNode, graphData[i][2]);
		node->edges.insert(edge);
		adjacentNode->parents.insert(std::make_pair(node, edge));
	}
	return graph;
}