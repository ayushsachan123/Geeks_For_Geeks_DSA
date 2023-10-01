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

Node* minVal(Node* root) {
	if (root->left == NULL) return root;
	return minVal(root->left);

}

Node* deleteFromBST(Node* root, int val) {
	//Base case
	if (root == NULL) return NULL;
	if (root->data == val) {
		//0 child
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		//1 child

		//Left child
		if (root->left != NULL && root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}

		//Right child
		if (root->right != NULL && root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		//2 child

		if (root->left != NULL && root->right != NULL) {
			int mini = minVal(root->right)->data;
			root->data = mini;
			root->right = deleteFromBST(root->right, mini);
			return root;
		}
	}

	else if (root->data > val) {
		//left part
		root->left = deleteFromBST(root->left, val);
		return root;
	}
	else {
		root->right = deleteFromBST(root->right, val);
		return root;
	}
	return root;
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

	root = deleteFromBST(root, 3);
	levelOrder(root);

	return 0;
}