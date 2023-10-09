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

bool twoSunInBST(Node* root, int target) {
	vector<int>v;
	inorder(root, v);
	int i = 0; int j = v.size() - 1;
	while (i < j) {
		if (v[i] + v[j] == target) return true;
		else if (v[i] + v[j] < target) i++;
		else if (v[i] + v[j] > target) j--;
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

	int ans = twoSunInBST(root, 4);
	cout << ans << endl;

	return 0;
}