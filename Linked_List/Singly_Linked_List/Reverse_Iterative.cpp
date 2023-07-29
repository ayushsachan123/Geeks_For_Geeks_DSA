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

//Naive Solution  Space O(n) --Using vector
Node *revList(Node *head){
	vector<int> arr;
	Node *ptr = head;
	while(ptr!=NULL){
		arr.push_back(ptr->data);
		ptr = ptr->next;
	}
	ptr = head;
	while(ptr!=NULL){
		ptr->data = arr.back();
		arr.pop_back();
		ptr = ptr->next;
	}
	return head;
}

//Efficient Solution --Changing links of the Node
//space - O(1) Time - O(n)

Node *revListE(Node *head){
	Node *curr = head;
	Node *prev = NULL;

	while(curr!=NULL){
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
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

//head = revList(head);
head = revListE(head);
printList(head);

return 0;
} 