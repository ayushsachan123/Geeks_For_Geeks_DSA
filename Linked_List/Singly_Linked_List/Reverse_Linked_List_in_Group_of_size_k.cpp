#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
    Node *next;
    Node(int x){
    	data = x;
    	next = NULL;
    }
};
//Recursive
//Time - O(n) Space - O(n/k)
Node *reverseInGroup(Node *head, int k){
	Node *curr = head;
	Node *prev = NULL;
	Node *next = NULL;

	int count =0;
	while(curr!=NULL && count<k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if(next!=NULL){
		Node *rest_head = reverseInGroup(next, k);
		head->next = rest_head;
	}
	return prev;
}

//Iterative Solution
Node *reverseI(Node *head,int k){

	Node *curr = head, *prevFirst = NULL;
    bool isFirstPass = true;

    while(curr!=NULL){
    	Node *first = curr, *prev = NULL;
    	int count = 0;

    	while(curr != NULL && count<k){
    		Node *next = curr->next;
    		curr->next = prev;
    		prev = curr;
    		curr = next;
    		count++;
    	}

    	if(isFirstPass) {
    		head = prev;
    		isFirstPass = false;
    	}
    	else{
    		prevFirst->next = prev;
    	}
    	prevFirst = first;
    }

    return head;
}

void printList(Node *head){
if(head == NULL)
	return; 

cout<<head->data<<" ";
printList(head->next);

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

Node *head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);                                                                                                                                                                                                                                           
head->next->next->next = new Node(40);
head->next->next->next->next = new Node(50);

//head = reverseInGroup(head,3);

head = reverseI(head, 3);
printList(head);

return 0;
} 