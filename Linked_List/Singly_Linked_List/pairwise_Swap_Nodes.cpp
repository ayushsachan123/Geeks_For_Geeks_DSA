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

//Swapping Data
//Time - O(n) Space - O(1)
Node *pairwiseSwap(Node *head){
	Node *ptr = head;

	while(ptr != NULL && ptr->next !=NULL){
		int temp = ptr->data;
		ptr->data = ptr->next->data;
        ptr->next->data = temp;
        ptr = ptr->next->next;
	}
 return head;
}

//Chaning Pointer
Node *pairwiseSwapC(Node *head){
	
  if(head == NULL || head->next == NULL) return;
  //To handle first two Node
  Node *curr = head->next->next;
  Node *prev = head;
  head = head->next;
  head->next = prev;

  while(curr != NULL && curr->next != NULL){
  	prev->next = curr->next;
  	prev = curr;
  	Node *next = curr->next->next;
  	curr->next->next = curr;
  	curr = next;
  }
  prev->next = curr;
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
head->next->next->next->next = new Node(50);

head = pairwiseSwap(head);
printList(head);

return 0;
} 