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

void levelOrder(Node *root){
	 if(root == NULL) return;
   queue<Node *>q;
   q.push(root);

   while(q.empty() == false){
   	int count = q.size();
   	for(int i=0;i<count;i++){
   		Node *curr = q.front();
   	    q.pop();

   	    cout<<curr->data<<" ";
   	if(curr->left != NULL){
   		q.push(curr->left);
   	}
   	if(curr->right != NULL){
   		q.push(curr->right);
   	}
   }
   cout<<endl;
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

levelOrder(root);

return 0;
} 