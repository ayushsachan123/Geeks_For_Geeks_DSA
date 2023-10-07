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

Node* solve(vector<int>&pre, int mini, int maxi, int &i) {
	if (i >= pre.size())
		return NULL;

	if (pre[i] < mini || pre[i] > maxi)
		return NULL;

	//If lie in range
	Node* root = new Node(pre[i++]);
	root->left = solve(pre, mini, root->data, i);
	root->right = solve(pre, root->data, maxi, i);

	return root;

}

Node* preorderToBST(vector<int>&pre) {
	int mini = INT_MIN;
	int maxi = INT_MAX;
	int i = 0;

	return solve(pre, mini, maxi, i);
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

	vector<int>v = {20, 10, 5, 15, 13, 35, 30, 42};
	Node* curr = preorderToBST(v);

	return 0;
}