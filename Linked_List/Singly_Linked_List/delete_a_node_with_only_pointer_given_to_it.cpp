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

//Delete the Node if the pointer to the Node which
//has to be deleted is given

Node *deleteNode(Node *ptr){
	Node *temp = ptr->next;
	ptr->data = temp->data;
	ptr->next = temp->next;

	delete temp;
	return ptr;
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

return 0;

} 