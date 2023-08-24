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

bool sumPro(Node *root){
	if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) return true;

    int sum = 0;
    if(root->left !=NULL) {
    	sum+=root->left->data;
    }
    if(root->right !=NULL){
    	sum+=root->right->data;
    }
    return (root->data == sum &&
     sumPro(root->left) && 
     sumPro(root->right));
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

bool ans = sumPro(root);
cout<<ans<<endl;

return 0;
} 