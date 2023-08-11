#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *prev;
	Node *next;
	Node(int x){
		data = x;
		prev = NULL;
		next = NULL;
	}
};

Node *Reverse(Node *head){
	Node *preptr = NULL;
	Node *curr = head;
	if(head == NULL)
		return head;

	while(curr !=NULL){
		Node *ptr = curr->next;
		curr->prev = ptr;
		curr->next = preptr;
        preptr = curr;
        curr = ptr;
	}
	return preptr;
}

void printList(Node *head){
	Node *ptr= head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

Node *head = new Node(10);
Node *temp1 = new Node(20);
Node *temp2 = new Node(30);

head->next = temp1;
temp1->prev = head;
temp1->next = temp2;
temp2->prev = temp1;

printList(head);
cout<<endl;
head = Reverse(head);
printList(head);

return 0;
} 