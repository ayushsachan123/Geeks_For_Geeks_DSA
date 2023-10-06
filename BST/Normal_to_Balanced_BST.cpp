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

Node* inorderToBST(int s, int e, vector<int>&v) {
	if (s > e) return NULL;
	int mid = (s + e) / 2;
	Node* root = new Node(v[mid]);
	root->left = inorderToBST(s, mid - 1, v);
	root->right = inorderToBST(mid + 1, e, v);

	return root;
}

Node* balamcedBST(Node* root) {
	vector<int>v;
	inorder(root, v);
	Node* curr = inorderToBST(0, v.size() - 1, v);

	return curr;
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

	return 0;
}