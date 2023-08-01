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

void printList(Node *head){
if(head == NULL)
	return; 

cout<<head->data<<" ";
printList(head->next);

}

Node *insertAtPos(Node *head, int pos, int data){
     Node *temp = new Node(data);
        if(pos == 1){
        	temp->next = head;
        	return temp;
        }

     Node *ptr = head;
    
     int i=1;
     while(i<pos-1){
     	ptr = ptr->next;
     }
//If user input position beyond the size of linkedlist
      if(ptr == NULL){
     	return temp;
     }

     temp->next = ptr->next;
     ptr->next = temp;

return head;
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

printList(head);
cout<<endl;
int pos = 2;
int data = 15;
insertAtPos(head,pos,data);

printList(head);

return 0;
} 