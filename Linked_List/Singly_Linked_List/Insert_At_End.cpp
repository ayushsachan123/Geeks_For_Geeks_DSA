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

Node *insertAtEnd(Node *head, int x){
	Node *ptr;

	Node *temp = new Node(x);
	if(head == NULL){
		return temp;
	}
	ptr = head;

    while(ptr->next != NULL){
    	ptr = ptr->next;      
    }

    ptr->next = temp;

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

Node *head = NULL;
head = insertAtEnd(head, 10);
head = insertAtEnd(head, 20);
head = insertAtEnd(head, 30);

printList(head);

return 0;
} 