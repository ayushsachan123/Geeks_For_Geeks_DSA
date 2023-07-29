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

Node *removeDuplicate(Node *head){
	Node *ptr = head;
	while(ptr!=NULL && ptr->next !=NULL){
		if(ptr->next->data == ptr->data){
			Node *curr = ptr->next;
			ptr->next = ptr->next->next;
			delete (curr);
		}
		else{
			ptr = ptr->next;
		}
	}
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
head->next->next = new Node(20);                                                                                                                                                                                                                                           
head->next->next->next = new Node(40);

head = removeDuplicate(head);
printList(head);

return 0;
} 