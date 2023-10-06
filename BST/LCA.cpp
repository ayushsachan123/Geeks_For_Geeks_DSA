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

Node* LCAinBST(Node* root, int p, int q) {
	//base case
	if (root == NULL) {
		return NULL;
	}
	if (root->data < p && root->data < q) {
		return LCAinBST(root->right, p, q);
	}
	if (root->data > p && root->data > q) {
		return LCAinBST(root->left, p, q);
	}

	return root;
}
//Or Iterative

Node *LCAinBSTI(Node* root, int p, int q) {

	while (root != NULL) {
		if (root->data < p && root->data < q) {
			root = root->right;
		}
		else if (root->data > p && root->data > q) {
			root = root->left;
		}
		else {
			return root;
		}
	}
	return NULL;
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

	Node* temp = LCAinBST(root, 1, 6);
	cout << temp->data << " " << endl;

	Node* temp1 = LCAinBSTI(root, 1, 6);
	cout << temp1->data << " " << endl;

	return 0;
}