#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
    Node *next;
    Node *random;
    Node(int x){
    	data = x;
    	next = NULL;
    	random = NULL;
    }
};

Node *clone(Node *head){
	Node *ptr = head, *nex , *temp;
    Node *ptr1 = head;

    while(ptr != NULL && ptr->next != NULL){
    	nex = ptr->next;
    	ptr->next = new Node(ptr->data);
    	ptr->next->next = nex;
    	ptr = nex;
    }

    ptr = head;
    while(ptr1 !=NULL && ptr1->next != NULL){
    	if(ptr1->random == NULL) 
    		ptr1->next->random = NULL;
        else
    	ptr1->next->random = ptr1->random->next;

    ptr1 = ptr1->next->next;

    }
    ptr = head->next;
    Node *ptr2 = head->next;
    delete head;
    while(ptr != NULL && ptr->next != NULL){
         temp = ptr->next;
    	ptr->next = ptr->next->next;
    	ptr = temp->next;
    	delete temp;
    }

    return ptr2;
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
head->next = new Node(5);
head->next->next = new Node(20);                                                                                                                                                                                                                                           
head->next->next->next = new Node(15);
head->next->next->next->next = new Node(20);
head->random = head->next->next;
head->next->random = head->next->next->next;
head->next->next->random = head;
head->next->next->next->random = head->next->next;
head->next->next->next->next->random = head->next->next->next;

head = clone(head);
printList(head);
return 0;
} 