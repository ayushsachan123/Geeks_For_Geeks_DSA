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

//Time Complexity - O(m+n) Space - O(1)

Node *sortedMerge(Node *a, Node *b){
    if(a == NULL) return b;
    if(b == NULL) return b;

    Node *head = NULL, *tail = NULL;
    if(a->data <= b->data){
        head = tail = a;
        a = a->next;
    }
    else{
    	head = tail = b;
    	b = b->next;
    }
    while(a!= NULL && b!= NULL){
    	if(a->data <= b->data){
    		tail->next = a;
    		tail = a;
    		a = a->next;
    	}
    	else{
    		tail->next = b;
    		tail = b;
    		b = b->next;
    	}
    }
    if(a == NULL){
    	tail->next = b;
    }
    else{
    	tail->next = a;
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

Node *head1 = new Node(10);
head1->next = new Node(20);
head1->next->next = new Node(30);                                                                                                                                                                                                                                           
head1->next->next->next = new Node(40);

Node *head2 = new Node(5);
head2->next = new Node(15);
head2->next->next = new Node(17);                                                                                                                                                                                                                                           
head2->next->next->next = new Node(18);
head2->next->next->next->next = new Node(35);


Node *head = sortedMerge(head1, head2);
printList(head);

return 0;
} 