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

//Naive Solution Time Complexity - o(n^2)
int height(Node *root){
	if(root == NULL) return 0;

	return max(height(root->left), height(root->right)) +1;
}

bool isBalanced(Node *root){
      if(root == NULL) return true;
      int lh = height(root->left);
      int rh = height(root->right);

      return (abs(lh - rh) <= 1 && 
      	isBalanced(root->left) &&
      	isBalanced(root->right));
}

//Effective Solution Time Complexity - o(n)
int isBalancedE(Node *root){
	if(root == NULL) return 0;

	int lh =  isBalancedE(root->left);
	if(lh == -1) return -1;
	int rh = isBalancedE(root->right);
	if(rh == -1) return -1;
	if(abs(lh - rh)>1) return -1;
	else return max(lh,rh) +1;
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

bool ans1 = isBalanced(root);
cout<<ans1<<endl;
int ans2 = isBalancedE(root);
cout<<ans2<<endl;

return 0;
} 