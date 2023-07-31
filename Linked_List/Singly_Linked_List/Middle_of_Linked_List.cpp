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

//Naive solution
void printmiddle(Node *head){
	if(head == NULL) return;
	int count = 0;
	Node *curr;
	for(curr = head; curr!=NULL; curr= curr->next){
		count++;
	}
	curr = head;
	for(int i=0;i<count/2;i++){
		curr = curr->next;
	}
	cout<<curr->data;
}

//Efficient Solution
void printMiddleE(Node *head){
	Node *slow = head;
	Node *fast = head;
	while(fast != NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	cout<<slow->data;
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

//printmiddle(head);

printMiddleE(head);

return 0;
} 