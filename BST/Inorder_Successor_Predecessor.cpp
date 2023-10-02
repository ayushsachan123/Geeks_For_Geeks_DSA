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

pair<int, int> predecessorSuccessor(Node* root, int key) {
	Node*temp = root;
	int pred = -1;
	int suc = -1;
	while (temp->data != key) {

		if (temp->data > key) {
			//It can be successor
			suc = temp->data;
			temp = temp->left;

		}
		else {
			//It can be predessor
			pred = temp->data;
			temp = temp->right;

		}
	}

	//Pred and succ

	//Pred
	Node* leftTree = temp->left;
	while (leftTree != NULL) {
		pred = leftTree->data;
		leftTree = leftTree->right;
	}

//Succ
	Node* rightTree = temp->right;
	while (rightTree != NULL) {
		suc = rightTree->data;
		rightTree = rightTree->left;
	}

	pair<int, int> ans = make_pair(pred, suc);

	return ans;
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

	pair<int, int> ans = predecessorSuccessor(root, 3);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}