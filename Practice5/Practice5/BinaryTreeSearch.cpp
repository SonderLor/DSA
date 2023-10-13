#include "BinaryTreeSearch.h"


Node::Node(std::string name) {
	this->name = name;
}

Node::~Node() {
	delete left;
	delete right;
}


BinaryTreeSearch::BinaryTreeSearch() {
	root = nullptr;
}

BinaryTreeSearch::BinaryTreeSearch(std::string name) {
	root = new Node(name);
}

BinaryTreeSearch::~BinaryTreeSearch() {
	delete root;
}

Node* BinaryTreeSearch::getMin(Node* root) {
	if (root == nullptr) {
		return nullptr;
	}
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* BinaryTreeSearch::getMax(Node* root) {
	if (root == nullptr) {
		return nullptr;
	}
	while (root->right != nullptr) {
		root = root->right;
	}
	return root;
}

Node* BinaryTreeSearch::searchNode(std::string name) {
	if (root == nullptr || root->name == name) {
		return root;
	}
	Node* temp = root;
	while (name.compare(temp->name) < 0 && temp->left != nullptr || name.compare(temp->name) > 0 && temp->right != nullptr) {
		if (name.compare(temp->name) < 0) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	return (name.compare(temp->name) == 0) ? temp : nullptr;
}

Node* BinaryTreeSearch::addNode(std::string name) {
	if (root == nullptr) {
		root = new Node(name);
		return root;
	}
	if (searchNode(name) != nullptr) {
		return nullptr;
	}
	Node* temp = root;
	while (name.compare(temp->name) < 0 && temp->left != nullptr || name.compare(temp->name) >= 0 && temp->right != nullptr) {
		if (name.compare(temp->name) < 0) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	if (name.compare(temp->name) < 0) {
		temp->left = new Node(name);
		return temp->left;
	}
	else {
		temp->right = new Node(name);
		return temp->right;
	}
}


Node* BinaryTreeSearch::deleteNode(std::string name) {
	if (searchNode(name) == nullptr) {
		return nullptr;
	}
	Node* temp = root;
	while (name.compare(temp->name) < 0 && temp->left->name != name || name.compare(temp->name) >= 0 && temp->right->name != name) {
		if (name.compare(temp->name) < 0) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	if (name.compare(temp->name) < 0) {
		if (temp->left->left == nullptr && temp->left->right == nullptr) {
			temp->left = nullptr;
		}
		else if (temp->left->left != nullptr) {
			temp->left = temp->left->left;
		}
		else if (temp->left->right != nullptr) {
			temp->left = temp->left->right;
		}
		else {
			temp->left = getMax(temp->left->left);
		}
	}
	else {
		if (temp->right->left == nullptr && temp->right->right == nullptr) {
			temp->right = nullptr;
		}
		else if (temp->right->left != nullptr) {
			temp->right = temp->right->left;
		}
		else if (temp->right->right != nullptr) {
			temp->right = temp->right->right;
		}
		else {
			temp->right = getMax(temp->right->left);
		}
	}
	return temp;
}


void BinaryTreeSearch::reverseBypass(Node* root) {
	if (root == nullptr) {
		return;
	}
	reverseBypass(root->left);
	reverseBypass(root->right);
	std::cout << root->name << " ";
}

void BinaryTreeSearch::simmetricalBypass(Node* root) {
	if (root == nullptr) {
		return;
	}
	reverseBypass(root->left);
	std::cout << root->name << " ";
	reverseBypass(root->right);
}

void BinaryTreeSearch::widthBypass() {
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		if (q.front()->left != nullptr) {
			q.push(q.front()->left);
		}
		if (q.front()->right != nullptr) {
			q.push(q.front()->right);
		}
		std::cout << q.front()->name << " ";
		q.pop();
	}
}

int BinaryTreeSearch::getNodeLevel(std::string name) {
	int level = 0;
	if (searchNode(name) == nullptr) {
		return -1;
	}
	if (root == nullptr || root->name == name) {
		return 0;
	}
	Node* temp = root;
	while (name.compare(temp->name) < 0 && temp->left != nullptr || name.compare(temp->name) > 0 && temp->right != nullptr) {
		if (name.compare(temp->name) < 0) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
		level++;
	}
	return level;
}

int BinaryTreeSearch::getHeight() {
	int maxLevel = 0;
	if (root == nullptr) {
		return 0;
	}
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		if (q.front()->left != nullptr) {
			q.push(q.front()->left);
		}
		if (q.front()->right != nullptr) {
			q.push(q.front()->right);
		}
		if (q.front()->left == nullptr && q.front()->right == nullptr && maxLevel < getNodeLevel(q.front()->name)) {
			maxLevel = getNodeLevel(q.front()->name);
		}
		q.pop();
	}
	return maxLevel;
}

Node* BinaryTreeSearch::getRoot() {
	return root;
}