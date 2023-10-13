#ifndef BINARYTREESEARCH_H


#include <iostream>
#include <string>
#include <queue>
#include <windows.h>


struct Node {
	std::string name;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(std::string name);
	~Node();
};


class BinaryTreeSearch {
private:
	Node* root;
	Node* getMin(Node* root);
	Node* getMax(Node* root);
public:
	BinaryTreeSearch();
	BinaryTreeSearch(std::string name);
	~BinaryTreeSearch();
	Node* searchNode(std::string name);
	Node* addNode(std::string name);
	Node* deleteNode(std::string name);
	void reverseBypass(Node* root);
	void simmetricalBypass(Node* root);
	void widthBypass();
	int getNodeLevel(std::string name);
	int getHeight();
	Node* getRoot();
};


#endif