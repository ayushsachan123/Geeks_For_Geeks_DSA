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
//By Using dummy Node => Method-3
bool isLoop(Node *head){

	Node *temp = new Node(-1);
	Node *curr = head;

	while(curr != NULL){
		if(curr->next == NULL) return false;
		if(curr->next == temp) return true;
		Node *curr_next = curr->next;
		curr->next = temp;
		curr = curr->next;
	}

	return false;
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

return 0;
} 