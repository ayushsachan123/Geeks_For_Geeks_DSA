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

Node *removeLoop(Node *head){
    Node *slow = head, *fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    //It means there is no loop
    if(slow != fast)
        return 0;
    slow = head;
//We are comparing slow->next == fast->next bcz we have
//to remove loop so for this we have to hold the address
//of the node from which the loop starts

while(slow->next == fast->next){
    slow = slow->next;
    fast = fast->next;
}
 fast->next == NULL;
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
head->next->next->next->next->next = head->next;

head = removeLoop(head);

printList(head);

return 0;
} 