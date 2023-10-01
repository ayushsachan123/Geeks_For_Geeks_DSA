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

//Method 1
void printSpiral(Node *root){
	queue<Node *>q;
    stack<int>s;
    bool reverse = false;
    q.push(root);
    while(q.empty() == false){
    	int count = q.size();
    	for(int i=0;i<count;i++){
    		Node *curr = q.front();
    		q.pop();
    		if(reverse)
    			s.push(curr->key);
    		else
    			cout<<curr->key<<" ";
    		if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
    	}
    	if(reverse){
    		while(s.empty() == false){
    			cout<<s.top()<<" ";
    			s.pop();
    		}
    	}
    	reverse = !reverse;
    	cout<<endl;
    }
}

//Method 2
 void printSpiral1(Node *root){
 	stack<Node *>s1,s2;
 	s1.push(root);
 	while(!s1.empty() || !s2.empty()){
 		while(!s1.empty()){
 			Node *curr = s1.top();
 			cout<<curr->key<<" ";
 			s1.pop();
 			if(curr->left !=NULL) s2.push(curr->left);
 			if(curr->right != NULL) s2.push(curr->right);
 		}
 		while(!s2.empty()){
            Node *curr = s2.top();
            cout<<curr->key<<" ";
            s2.pop();
 			if(curr->right != NULL) s1.push(curr->right);
 			if(curr->left !=NULL) s1.push(curr->left);
 		}
 		
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

printSpiral(root);
cout<<endl;
printSpiral1(root);
return 0;
} 