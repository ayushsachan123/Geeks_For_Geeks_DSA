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

Node *temp1 = new Node(-1);
Node *temp2 = new Node(-1);
Node *ptr1 = head;
    temp1 = revListE(ptr1);

    Node *ptr2 = temp1;
     temp2 = revListE(ptr2);
    printList(temp1);
     printList(head);

return 0;
} 