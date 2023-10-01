#include<bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

void inorder(Node* root, vector<int>&v) {
	if (root == NULL) {
		return;
	}
	inorder(root->left, v);
	v.push_back(root->data);
	inorder(root->right, v);
}

Node* flatten(Node* root) {
	vector<int>inorderVal;
	inorder(root, inorderVal);

	Node* newRoot = new Node(inorderVal[0]);
	Node* curr = newRoot;
	for (int i = 1; i < inorderVal.size(); i++) {

		Node* temp = new Node(inorderVal[i]);
		curr->left = temp;
		curr->right = NULL;
		curr = temp;
	}

	curr->left = NULL;
	curr->right = NULL;

	return newRoot;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node* root = new Node(8);
	root->left = new Node(3);
	root->left->left = new Node(1);
	root->left->right = new Node(6);
	root->right = new Node(10);
	root->right->right = new Node(14);

	Node* ans = flatten(root);

	return 0;
}
