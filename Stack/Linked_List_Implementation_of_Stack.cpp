#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int d){
		data = d;
		next = NULL;
	}
};

//Time Complexity - O(1)
struct myStack{
	Node *head;
	//we are taking size to implement size function in O(1) time.
	int sz;
	myStack(){
		head = NULL;
		sz = 0;
	}
	void push(int x){
		Node *temp = new Node(x);
		temp->next = head;
		head = temp;
		sz++;
	}
	int pop(){
		if(head == NULL){
			return INT_MAX;
		}
		int res = head->data;
		Node *temp = head;
		head = head->next;
		delete (temp);
		sz--;
		return res;
	}
	int size(){
		return sz;
	}
	bool isEmpty(){
		return (head== NULL);
	}
	int peek(){
		if(head == NULL){
			return INT_MAX;
		}
		return head->data;
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 