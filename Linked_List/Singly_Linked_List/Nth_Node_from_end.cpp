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

//Using length of linked List

void nthNode(Node *head, int n){
   Node *ptr = head;

   int count = 0;
   while(ptr!=NULL){
   	count++;
   	ptr = ptr->next;
   }
   ptr = head;
   if(count<n) return;
   
 for(int i=1;i<(count-n+1);i++){
 	ptr = ptr->next;
 }
 cout<<ptr->data;
}

//Using Two pointer
void nthNodeE(Node *head, int n){

	if(head == NULL) return;
	Node *first = head;
    for(int i=0;i<n;i++){
    	if(first == NULL) return;
    	first = first->next;
    }
    Node *second = head;
    while(first!=NULL){
    	second = second->next;
    	first = first->next; 
    }
    cout<<(second->data);
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

// printList(head);

nthNode(head,2);
cout<<endl;
nthNodeE(head,2);

return 0;
} 