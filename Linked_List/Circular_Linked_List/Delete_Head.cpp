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

//Naive Solution

Node *deleteHead(Node *head){
	if(head == NULL)
		return NULL;

	if(head->next == head){
		delete head;
		return NULL;
	}

	else{
		Node *ptr = head;
		while(ptr->next !=head){
			ptr = ptr->next;
		}
		ptr->next = head->next;
		delete head;

		return ptr->next;
	}
}

Node *deleteHead1(Node *head){

	if(head == NULL){
		return NULL;
	}
	if(head->next == head){
		delete head;
		return NULL;
	}
    
    else{
    	head->data = head->next->data;
         
         Node *temp = head->next;
    	head->next = head->next->next;
    	 delete temp;

    	return head;
    }
}

void printList(Node *head){ 
 
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
head->next->next = new Node(30);
head->next->next->next = new Node(40);
head->next->next->next->next = head; 

// head = deleteHead(head);
// printList(head);

head = deleteHead1(head);
printList(head);

return 0;
} 