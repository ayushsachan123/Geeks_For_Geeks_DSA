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

bool isBST(Node* root, int min, int max) {
	if (root == NULL) return true;

	if (root->data >= min && root->data <= max) {
		bool left = isBST(root ->left, min, root->data);
		bool right = isBST(root ->right, root->data, max);
		return left && right;
	}
	else
		return false;
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

	bool ans = isBST(root, INT_MIN, INT_MAX);
	cout << ans << endl;

	return 0;
}