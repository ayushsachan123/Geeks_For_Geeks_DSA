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

Node *segregate(Node *head){
	Node *eS = NULL, *eE = NULL, *oS = NULL, *oE = NULL;
	Node *ptr = head;
	while(ptr!= NULL){

		int x = ptr->data;
		if(x%2 == 0){
			if(eS == NULL){
               eS = ptr;
               eE = eS;
			}
			else{
				eE->next = ptr;
				eE = eE->next;
			}
		}
		else{
			if(oS == NULL){
				oS = ptr;
				oE = oS;
			}
			else{
				oE->next = ptr;
				oE = oE->next;
			
		}
	}
	ptr = ptr->next;
}
//After Loop Ends connect oS & oE if we have
	//to write oE first so,
	if(oS == NULL || eS == NULL){
		return head;
	}
	eE->next = oS;
	oE->next = NULL;

	return eS;
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
head->next = new Node(25);
head->next->next = new Node(30);                                                                                                                                                                                                                                           
head->next->next->next = new Node(45);
head->next->next->next->next = new Node(50);

head = segregate(head);
printList(head);

return 0;
} 