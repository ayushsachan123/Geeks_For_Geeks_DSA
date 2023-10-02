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

void levelOrder(Node *root) {
	if (root == NULL) return;
	queue<Node *>q;
	q.push(root);

	while (q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; i++) {
			Node *curr = q.front();
			q.pop();

			cout << curr->data << " ";
			if (curr->left != NULL) {
				q.push(curr->left);
			}
			if (curr->right != NULL) {
				q.push(curr->right);
			}
		}
		cout << endl;
	}

}


Node* insertIntoBST(Node* root, int d) {
	//base case
	if (root == NULL) {
		root = new Node(d);
		return root;
	}
	if (d > root->data) {
		//Insert in right part
		root->right = insertIntoBST(root->right, d);
	}
	else {
		//Insert in left part
		root->left = insertIntoBST(root->left, d);
	}
	return root;
}

void takeInput(Node* &root) {
	int data;
	cin >> data;

	while (data != -1) {
		root =  insertIntoBST(root, data);
		cin >> data;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node* root = NULL;
	cout << "Enter data to create BST" << endl;
	takeInput(root);
	cout << "Printing the BST" << endl;
	levelOrder(root);
	return 0;
}