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

const int EMPTY = -1; 
//Serialization - Follow preorder traversal
void serialize(Node *root,vector<int>&v){
	if(root == NULL){
		v.push_back(EMPTY);
		return;
	}
	v.push_back(root->data);
	serialize(root->left,v);
	serialize(root->right,v);
}


//Deserialization - follow preorder Traversal
int inde = 0;
Node *deSerialize(vector<int> &v){
   if(inde == v.size()) return NULL;

   int val = v[inde];
    inde++;
   if(val == EMPTY) return NULL;

   Node *root = new Node(val);
   root->left = deSerialize(v);
   root->right = deSerialize(v);

   return root;
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

vector<int>v1;
vector<int>v2 = {10,20,-1,-1};

serialize(root,v1);
for(int i=0;i<v1.size();i++){
	cout<<v1[i]<<" ";
}
Node *ans = deSerialize(v2);
return 0;
} 