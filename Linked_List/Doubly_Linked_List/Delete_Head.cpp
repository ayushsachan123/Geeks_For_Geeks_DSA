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

Node *deleteHead(Node *head){

	if(head == NULL){
		return NULL;
	}

	if(head->next == NULL){
		delete head;
		return NULL;
	}

	else{
		       Node *ptr = head;
	         Node *preptr = ptr->next;
	         
              preptr->prev = NULL;
             delete ptr;
             return preptr;
	}

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

head = deleteHead(head);
printList(head);

return 0;
} 