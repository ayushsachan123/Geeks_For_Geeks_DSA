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

printList(head);

return 0;
} 