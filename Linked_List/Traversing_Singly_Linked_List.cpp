#include<bits/stdc++.h>

using namespace std;

struct Node{
	 int data;
	 Node *next;
	 Node (int x){
	 	data =x;
	 	next = NULL;
	 }
};

void printList(Node *head){
	Node *curr = head;
	while(curr!=NULL){
		cout<<curr->data<<" ";
		curr = curr->next;
	}
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
printList(head);

return 0;
} 