#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int k){
		data = k;
		left = NULL;
		right = NULL;
	}
};

void inorder(Node *root){
	stack<Node *>s;
    Node *curr = root;
    while(curr != NULL || s.empty() == false){
    	while(curr !=NULL){
    		s.push(curr);
    		curr = curr->left;
    	}
    	curr = s.top();
    	s.pop();
    	cout<<curr->data<<" ";
    	curr = curr->right; 
    }
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

Node *root = new Node(10);
root->left = new Node(20);
root->right = new Node(30);
root->left->left = new Node(40);

inorder(root);
return 0;
} 