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

//Naive solution
int i = 0;
void smallest(Node* root, int k) {
	//base case
	if (root != NULL) {
		//L
		smallest(root->left, k);
		//N
		i++;
		if (i == k) {
			cout << root->data;
			return;
		}

		//R
		return smallest(root->right, k);
	}
}

//OR
int solve(Node* root, int &i, int k) {
	//base case
	if (root == NULL) {
		return -1;
	}//Inorder - LNR since it is sorted, we increment i when a node is found

	//L
	int left = solve(root->left, i, k);
	if (left != -1) {
		return left;
	}
	//N
	i++;
	if (i == k)
		return root->data;
	//R
	return solve(root->right, i, k);
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

	smallest(root, 2);
	int i = 0;
	int ans = solve(root, i, 2);
	cout << endl;
	cout << ans << endl;

	return 0;
}