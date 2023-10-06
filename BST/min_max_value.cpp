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

Node* min(Node* root) {
	if (root == NULL || root->left == NULL) return root;
	return min(root->left);

}

vector<int>v;
void minVal(Node* root) {
	if (root == NULL) return;
	if (root->left == NULL) {
		v.push_back(root->data);
		return;
	}
	v.push_back(root->data);
	minVal(root->left);
}

Node* max(Node* root) {
	if (root == NULL || root->right == NULL) return root;
	return max(root->right);
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

	Node* mi = min(root);
	cout << mi->data << endl;
	minVal(root);
	Node* mx = max(root);
	cout << mx->data << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}