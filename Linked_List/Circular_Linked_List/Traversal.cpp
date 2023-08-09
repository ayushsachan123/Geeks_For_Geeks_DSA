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
 
//For Loop 
void printList(Node *head){ 
 
      if(head == NULL)
      	return;

       cout<<(head->data)<<" ";
       for(Node *ptr = head->next; ptr!=head; ptr=ptr->next)
       	cout<<(ptr->data)<<" ";
}

//Do while
void printLstDo(Node *head){
	 if(head == NULL)
      	return;
      Node *ptr = head;
      do{
      	cout<<(ptr->data)<<" ";
      	ptr = ptr->next;
      }while(ptr != head);

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

printList(head);
cout<<endl;
printLstDo(head);

return 0;
} 