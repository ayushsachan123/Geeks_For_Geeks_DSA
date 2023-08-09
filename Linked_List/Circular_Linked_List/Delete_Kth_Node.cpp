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

Node *deleteKthNode(Node *head, int k){
  if(head == NULL) return NULL;
  if(head->next == head){
  	delete head;
  	return NULL;
  }

  Node *ptr = head;
  for(int i=0; i<k-2;i++){
      ptr = ptr->next;
  }

  Node *temp = ptr->next;
  ptr->next = ptr->next->next;

  delete temp;

  return head;
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

deleteKthNode(head, 3);
printList(head);

return 0;
} 