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
//By Floyd_Cycle => Method-5

bool isLoop(Node *head){
    Node *slow_p = head, *fast_p = head;
    while(fast_p !=NULL && fast_p->next != NULL){

        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        //Condition return below bcz if we write above
        //then it return true for every linked list

        if(slow_p == fast_p)
            return true;
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

bool ans = isLoop(head);
cout<<ans<<endl;

return 0;
} 