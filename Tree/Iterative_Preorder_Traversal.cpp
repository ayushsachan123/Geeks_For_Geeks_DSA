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
void preorder(Node *root){
	if(root == NULL) return;
	stack<Node *>s;
    Node *curr = root;
    s.push(root);
    while(s.empty() == false){
    	Node *curr = s.top();
    	cout<<curr->data<<" ";
    	s.pop();
    	//write Right first bcz it is an LIFO and we want to traverse left first
    	if(curr->right != NULL) s.push(curr->right);
    	if(curr->left != NULL) s.push(curr->left);
    }
}

//Efficient Solution Space Complexity - o(h)

void preorderE(Node *root){
	if (root == NULL)
        return;
 
    stack<Node*> st;
 
    // start from root node (set current node to root node)
    Node* curr = root;
 
    // run till stack is not empty or current is
    // not NULL
    while (!st.empty() || curr != NULL) {
        // Print left children while exist
        // and keep pushing right into the
        // stack.
        while (curr != NULL) {
            cout << curr->data << " ";
 
            if (curr->right)
                st.push(curr->right);
 
            curr = curr->left;
        }
 
        // We reach when curr is NULL, so We
        // take out a right child from stack
        if (st.empty() == false) {
            curr = st.top();
            st.pop();
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

preorder(root);
cout<<endl;
preorderE(root);
return 0;
}   