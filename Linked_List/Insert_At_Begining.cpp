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

Node *insertAtBeg(Node *head, int x){
 Node *temp = new Node(x);
 temp->next = head;

return temp;
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

head = insertAtBeg(head, 10);
head = insertAtBeg(head, 20);
head = insertAtBeg(head, 30);
head = insertAtBeg(head, 40);

printList(head);

return 0;
} 