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

//Global bcz it should be able to accessible to all

Node *convertBinary(Node *root){
	Node* prev = NULL;
	if(root == NULL){
		return root;
	}
	
	Node *head = convertBinary(root->left);
      if(prev == NULL){
      	head = root;
      }
      else{
      	root->left = prev;
      	prev->right = root;
      }
      prev = root;
      convertBinary(root->right);
      return head;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

return 0;
} 