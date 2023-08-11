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

Node *insertAtHead(Node *head, int x){

Node *temp = new Node(x);

if(head == NULL){
	temp->next = temp;
	temp->prev = temp;
	return temp;
}
temp->prev = head->prev;
temp->next = head;
head->prev->next = temp;
head->prev = temp;

return temp;
}

void printList(Node *head){
	Node *ptr = head;
	   if(head == NULL)
      	return;

       cout<<(head->data)<<" ";
       for(Node *ptr = head->next; ptr!=head; ptr=ptr->next)
       	cout<<(ptr->data)<<" ";
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

Node *head = new Node(10);
head->next = new Node(20);
head->next->prev = head;
head->next->next = new Node(30);
head->next->next->prev = head->next;
head->next->next->next = new Node(40);
head->next->next->next->next = head;
head->next->next->next->prev = head->next->next;
head->prev = head->next->next->next;

head = insertAtHead(head, 50);
printList(head);

return 0;
} 