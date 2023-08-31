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

//Naive Solution 
bool findPath(Node *root, vector<Node *>&p, int n){
	if(root == NULL) return false;
	p.push_back(root);
	if(root->key == n) return true;
	if(findPath(root->left,p,n)|| findPath(root->right,p,n))
		return true;
	p.pop_back();
	return false;
}

Node *lowestAnsistor(Node *root,int n1, int n2){
vector<Node *>path1,path2;
if(findPath(root,path1,n1) == false || findPath(root,path2,n2) == false)
return NULL;
for(int i=0;i<path1.size()-1 && path2.size()-1;i++){
	if(path1[i+1] != path2[i+1])
		return path1[i];
}
  return NULL;

}

//Efficient Solution
Node *lowestAnsistorE(Node *root,int n1,int n2){
	if(root == NULL) return NULL;
	if(root->key == n1 || root->key == n2) return root;

	Node *lca1 = lowestAnsistorE(root->left,n1,n2);
	Node *lca2 = lowestAnsistorE(root->right,n1,n2);
	if(lca1 != NULL && lca2 != NULL)
		return root;
	if(lca1 != NULL)
		return lca1;
	else
		return lca2;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->left->left = new Node(60);
    root->right->right = new Node(50);
    root->right->right->left = new Node(70);
    root->right->right->right = new Node(80);

 Node *curr1 = lowestAnsistor(root,60,70);
  cout<<curr1->key<<endl;
Node *curr2 = lowestAnsistorE(root,60,70);
 cout<<curr2->key<<endl;
 
return 0;
} 