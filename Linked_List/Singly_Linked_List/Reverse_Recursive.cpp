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

//Recursive First reverse the last n-1 node then the first Node
Node *reverse1(Node *head){
  
  if(head == NULL || head->next == NULL) return head;
   Node *rest_head = reverse1(head->next);
   Node *rest_tail = head->next;
   rest_tail->next = head;
   head->next = NULL;
   return rest_head;
}

void printList(Node *head){
if(head == NULL)
	return; 

cout<<head->data<<" ";
printList(head->next);

}

//First reverse the first n-1 node the the nth node
Node *reverse2(Node *curr, Node *prev){

  if(curr == NULL) return prev;
  Node *next = curr->next;
  curr->next = prev;
  return reverse2(next,curr);
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

//head = reverse1(head);
head = reverse2(head,NULL);
printList(head);

return 0;
} 