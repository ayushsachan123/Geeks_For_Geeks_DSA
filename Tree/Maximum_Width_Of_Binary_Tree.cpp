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

//Time Complexity - o(n) Space Complexity - o(n)
int maxWidth(Node *root){
	if(root == NULL) return 0;
	queue<Node *>q;
	q.push(root);
	int res =0;
	while(q.empty() ==false){
		int count = q.size();
		res = max(res,count);
		for(int i=0;i<count;i++){
			Node *curr = q.front();
			q.pop();
			if(curr->left != NULL)
				q.push(curr->left);
			if(curr->right != NULL)  
				q.push(curr->right);
		}
	}
	return res;
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

int ans = maxWidth(root);
cout<<ans<<endl;

return 0;
} 