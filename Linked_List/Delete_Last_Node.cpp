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

Node *deleteAtEnd(Node *head){
	while(head == NULL)
		return NULL;

	while(head->next == NULL){
		delete head;
		return NULL;
	}

	Node *ptr=head;
	while(ptr->next->next !=NULL){
		ptr = ptr->next;
	}
	delete(ptr->next);
	ptr->next = NULL;

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

printList(head);
cout<<endl;
head = deleteAtEnd(head);
head = deleteAtEnd(head);

printList(head);

return 0;
} 

//Time Complexity - o(n)