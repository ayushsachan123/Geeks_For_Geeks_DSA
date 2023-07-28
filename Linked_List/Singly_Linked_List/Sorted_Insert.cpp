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

Node *sortedInsert(Node *head, int x){
   Node *ptr = head;
   Node *temp = new Node(x);

   if(head == NULL) return temp;
   
   if(x< head->data) {
   	temp->next = head;
   	return temp;
   }

   while(ptr->next !=NULL && ptr->next->data <x){
            	ptr = ptr->next;
           }

   		temp->next = ptr->next;
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

Node *head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);                                                                                                                                                                                                                                           
head->next->next->next = new Node(40);

head = sortedInsert(head, 25);
printList(head);

return 0;
} 