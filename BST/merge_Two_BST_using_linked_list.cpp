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

void convertIntoSortedDLL(Node *root, Node* &head) {
	//base case
	if (root == NULL) return;
	convertIntoSortedDLL(root->right, head);
	root->right = head;
	if (head != NULL)
		head->left = root;

	head = root;

	convertIntoSortedDLL(root->left, head);

}

Node* mergeLinkedList(Node *head1, Node* head2) {
	Node* head = NULL;
	Node* tail = NULL;

	while (head1 != NULL && head2 != NULL) {
		if (head1->data < head2->data) {
			if (head == NULL) {
				head = head1;
				tail = head1;
				head1 = head1->right;
			}
			else {
				tail->right = head1;
				head1->left = tail;
				tail = head1;
				head1 = head1->right;
			}
		}

		else {
			if (head == NULL) {
				head = head2;
				tail = head2;
				head1 = head2->right;
			}
			else {
				tail->right = head2;
				head2->left = tail;
				tail = head2;
				head2 = head2->right;
			}

		}

	}

	while (head1 != NULL) {
		tail->right = head1;
		head1->left = tail;
		tail = head1;
		head1 = head1->right;
	}

	while (head2 != NULL) {
		tail->right = head2;
		head2->left = tail;
		tail = head2;
		head2 = head2->right;
	}

	return head;
}

int countNode(Node* head) {
	int count = 0;
	Node* curr = head;

	while (curr != NULL) {
		count++;
		curr = curr->right;
	}
	return count;
}

Node* sortedLLToBST(Node* head, int n) {
	//base case
	if (n <= 0 || head == NULL) {
		return NULL;
	}

	Node* left = sortedLLToBST(head, n / 2);
	Node* root = head;
	root->left = left;

	head = head->right;

	root->right = sortedLLToBST(head, n - n / 2 - 1);

	return root;
}

Node* mergeBST(Node* root1, Node* root2) {

//Step 1: convert bst into sorted DLL in-place
	Node* head1 = NULL;
	convertIntoSortedDLL(root1, head1);
	head1->left = NULL;

	Node* head2 = NULL;
	convertIntoSortedDLL(root2, head2);
	head2->left = NULL;

//Step 2: Merge Sorted Linked List
	Node* head = mergeLinkedList(root1, root2);

//Step 3: Convert DLL to BST
	int n = countNode(head);

	return sortedLLToBST(head, n);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root1 = new Node(100);
	root1->left = new Node(50);
	root1->right = new Node(300);
	root1->left->left = new Node(20);
	root1->left->right = new Node(70);

	Node *root2 = new Node(80);
	root2->left = new Node(40);
	root2->right = new Node(120);



	return 0;
}