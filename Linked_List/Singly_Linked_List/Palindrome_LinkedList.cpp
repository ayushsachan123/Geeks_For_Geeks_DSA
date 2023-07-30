#include<bits/stdc++.h>

using namespace std;

struct Node{
	char data;
    Node *next;
    Node(int x){
    	data = x;
    	next = NULL;
    }
};

//Naive solution  Time - O(n) Space - O(n)
bool palindrome(Node *head){
   stack<char>st;
   for(Node *curr = head;curr !=NULL; curr = curr->next){
   	    st.push(curr->data);
   }

   for(Node *curr = head; curr!= NULL; curr = curr->next){
   	if(st.top() != curr->data)
   		return false;
   	st.pop();
   }
   return true;
}

Node *reverse(Node *head){
  
  if(head == NULL || head->next == NULL) return head;
   Node *rest_head = reverse(head->next);
   Node *rest_tail = head->next;
   rest_tail->next = head;
   head->next = NULL;
   return rest_head;
}

//Efficient Solution Time - o(n) Space - O(1)
bool palindromeE(Node *head){
	Node *slow = head, *fast = head;
    while(fast->next != NULL && fast->next->next !=NULL){
         slow = slow->next;
    	fast = fast->next->next;
    }
Node *rev = reverse(slow->next);
Node *curr = head;
while(rev != NULL){
	if(rev->data != curr->data)
		return false;
	rev = rev->next;
	curr = curr->next;
	
}
return true;
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

Node *head = new Node('r');
head->next = new Node('a');
head->next->next = new Node('d');                                                                                                                                                                                                                                           
head->next->next->next = new Node('a');
head->next->next->next->next = new Node('r');

// bool ans1 = palindrome(head);
// cout<<ans1<<endl;

bool ans2 = palindromeE(head);
cout<<ans2<<endl;
//printList(head);

return 0;
} 