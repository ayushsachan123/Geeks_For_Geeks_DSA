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

//Recursive
bool search(Node* root, int x) {
	if (root == NULL) return false;
	if (root->data == x) return true;
	if (root->data > x) {
		return search(root->left, x);
	}
	else {
		return search(root->right, x);
	}
	return false;
}

//Iterative
bool searchI(Node* root, int x) {
	Node* temp = root;

	while (temp != NULL) {
		if (temp->data == x)
			return true;
		if (temp->data > x)
			temp = temp->left;
		else
			temp = temp->right;
	}
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

	bool ans = search(root, 14);
	cout << ans << endl;

	bool ans1 = searchI(root, 14);
	cout << ans1 << endl;

	return 0;
}