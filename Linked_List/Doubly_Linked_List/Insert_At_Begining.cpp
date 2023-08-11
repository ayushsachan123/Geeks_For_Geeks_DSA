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


Node *insertAtBegin(Node *head, int x){
	Node *ptr = head;
	Node *temp = new Node(x);
	temp->next = ptr;
	if(head !=NULL){
		ptr->prev = temp;
	}
	
	return temp;
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

head = insertAtBegin(head,40);

return 0;
} 