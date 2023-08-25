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

//Here is - in array start, ie - in array end
int preIndex = 0;
Node *cTree(int in[], int pre[], int is,int ie){
if(is>ie) return NULL;
Node *root = new Node(pre[preIndex++]);

int inIndex;
for(int i=is;i<=ie;i++){
	if(in[i] == root->key){
		inIndex = i;
		break;
	}
}
root->left = cTree(in, pre,is,inIndex-1);
root->right = cTree(in,pre,inIndex+1,ie);

return root;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 