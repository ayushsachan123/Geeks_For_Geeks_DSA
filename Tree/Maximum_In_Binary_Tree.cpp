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

int getMax(Node *root){
	if(root == NULL) return INT_MIN;
	else{
		return max(root->data, max(getMax(root->left),getMax(root->right)));
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

int ans = getMax(root);
cout<<ans<<endl;

return 0;
} 