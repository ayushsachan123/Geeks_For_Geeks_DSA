#include<bits/stdc++.h>

using namespace std;

struct Queue{
	int *arr;
	int front, cap, size;
	Queue(int c){
		arr = new int[c];
		cap = c;
		front = 0;
		size = 0;
	}
	bool isFull(){
		return (size == cap); 
	}
	bool isEmpty(){
		return (size == 0);
	}
	int getFront(){
		if(isEmpty()) return -1;
		else return front;
	}
	int getRear(){
		if(isEmpty()) return -1;
		else return (front + size -1)%cap;
	}
	void enqueue(int x){
		if(isFull()) return;
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear] = x;
        size++;
	}
	void dequeue(){
		if(isEmpty()) return;
		front = (front+1)%cap;
		size--;
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

return 0;
} 