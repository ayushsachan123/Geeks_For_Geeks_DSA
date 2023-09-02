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

void printDist(Node *root, int k){
	if(root == NULL) return;
	if(k == 0 ) cout<<root->data<<" ";
	else{
		printDist(root->left,k--);
		printDist(root->right,k--);
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

printDist(root,1);

return 0;
} 