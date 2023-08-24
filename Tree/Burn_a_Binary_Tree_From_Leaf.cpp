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

int res =0;
int burnTime(Node *root,int leaf,int &dist){
	if(root == NULL) return 0;
	if(root->data == leaf){
		dist = 0;
		return 1;
	}
	int ldist = -1,rdist = -1;
    int lh = burnTime(root->left,leaf,ldist);  //return left height and set ldist
    int rh = burnTime(root->right,leaf,rdist);
    if(ldist !=-1){ //for root = 10 50 lies in the left side so ldist != -1 
    	dist = ldist +1;
    	res = max(res,dist+rh);
    }
    else if(rdist !=-1){
    	dist = rdist +1;
    	res = max(res,dist+lh);
    }
    return max(lh,rh)+1;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->left->left = new Node(40);
    root->left->left->left = new Node(60);
    root->left->left->left->left = new Node(70);

int dist = -1;

int ans = burnTime(root,50,dist);
cout<<res<<endl;

return 0;
} 