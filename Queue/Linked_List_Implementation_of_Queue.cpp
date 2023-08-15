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

struct Queue{
	Node *front, *rear;
	int size;
	Queue() {
		front = NULL;
		rear = NULL;
		size =0;
	}
	void enqueue(int x){
		Node *temp = new Node(x);
		size++;
		if(front == NULL) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	void dequeue(){
		if(front == NULL){
			return;
		}
		size--;
		Node *temp = front;
		front = front->next;
		//Deleting last item of queue front become NULL
		if(front == NULL){
			front = NULL;
			rear = NULL;
		}
		delete(temp);
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 