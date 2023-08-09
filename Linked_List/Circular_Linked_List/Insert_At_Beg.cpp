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

//Naive Solution  O(n)
Node *insertAtBeg(Node *head, int x){
	Node *temp = new Node(x);
	Node *ptr = head;

	if(head == NULL){
		temp->next = temp;
		return temp;
	}

	else{
		while(ptr->next != head){
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->next = head;

	}
return temp;
}

//O(1)
//In this case we first insert temp between 1st and second node 
//then swap the value of ist and second node.

Node *insertAtBeg1(Node *head, int x){
      Node *temp = new Node(x);
	Node *ptr = head;

	if(head == NULL){
		temp->next = temp;
		return temp;
	}

	else{
		temp->next = head->next;
		head->next = temp;
		int t = head->data;
		head->data = temp->data;
		temp->data = t;
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

// head = insertAtBeg(head, 50);
// printList(head);

head = insertAtBeg1(head, 80);
printList(head);

return 0;
} 