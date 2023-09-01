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

//Naive Method
int count_Node(Node *root){
    if(root == NULL)
    	return 0;

	return count_Node(root->left) +count_Node(root->right)+1;
}

//Efficient Method
int count_NodeE(Node *root){
	int lh =0,rh =0;
	Node *curr = root;
	while(curr!=NULL){
		lh++;
		curr = curr->left;
	}
	curr = root;
	while(curr !=NULL){
		rh++;
		curr = curr->right;
	}
	if(lh == rh)
		return (pow(2,lh)-1);
	return 1+ count_NodeE(root->left) + count_NodeE(root->right);

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

int ans = count_Node(root);
cout<<ans<<endl;

return 0;
} 