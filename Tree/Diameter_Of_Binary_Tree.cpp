#include<bits/stdc++.h>

using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	Node(int k){
		key = k;
		left = NULL;
		right = NULL;
	}
};

//Naive Solution Time Complexity - o(n^2)
int height(Node *root){
	if(root == NULL) return 0;
	else{
		return (1 + max(height(root->left),height(root->right)));
	}
}

int diameter(Node *root){
	if(root == NULL) return 0;
	int d1 = 1 + height(root->left) + height(root->right);
	int d2 = diameter(root->left);
	int d3 = diameter(root->right);

	return max(d1,max(d2,d3));
}

//Effective Solution

int res = 0;
int diameterE(Node *root){
	if(root == NULL) return 0;
	int lh = height(root->left);
	int rh = height(root->right);
	res = max(res,1+lh+rh);
	return 1+ max(lh,rh);
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
int ans1 = diameter(root);
cout<<ans1<<endl;

int ans2 = diameterE(root);
cout<<ans2<<endl;

return 0;
} 