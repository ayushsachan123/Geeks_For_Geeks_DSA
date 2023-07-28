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

//Iterative
int searchLL(Node *head, int x){
      Node *ptr = head;
      int count = 1;
      while(ptr != NULL){
          if(ptr->data == x){
          	  return count;
          }
          else{
              count++;
              ptr = ptr->next;
          }
      }
      return -1;
}

//Recursive

int searchRecLL(Node *head, int x){
  Node *ptr = head;
  if(ptr == NULL)
    return -1;
  if(ptr->data == x)
    return 1;
  else{
    int res = searchRecLL(head->next,x);
    if(res == -1) 
      return -1;
    else
      return res+1;
  }
 
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

// printList(head);

int key = 30;

int ans1 = searchLL(head, key);
cout<<ans1<<endl;

int ans2 = searchRecLL(head, key);
cout<<ans2<<endl;


return 0;
} 

//Time Complexity, space complexity - Iterative
//o(n) , 0(1)

//Time Complexity, space complexity - Recursive
//o(n) , o(n)