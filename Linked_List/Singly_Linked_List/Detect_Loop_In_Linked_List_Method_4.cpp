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
//By Using Hassing => Method-4
//Time - O(n) Space - O(n)

bool isLoop(Node *head){
    unordered_set<Node *> s;

    for(Node *curr = head; curr!=NULL; curr = curr->next){
    	if(s.find(curr) != s.end())
    		return true;

    	   s.insert(curr);
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