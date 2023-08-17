#include<bits/stdc++.h>

using namespace std;

//Using circular Array
struct Deque{
	int front,size,cap;
	int *arr;
	Deque(int c){
		cap = c;
		front = 0;
		size = 0;
		arr = new int[cap];
	}
	
	bool isEmpty(){
		return (size == 0);
	}
	bool isFull(){
		return (size == cap);
	}
    int getFront(){
    	if(isEmpty()) return -1;
    	else return arr[front];
    }
    int getRear(){
    	if(isEmpty()) return -1;
    	else return (front + size -1)%cap;
    }
    void deleteFront(){
    	if(isEmpty()) return;
    	front = (front+1)%cap;
    	size--;
    }
    void insertRear(int x){
    	if(isFull()) return;
    	int new_rear = (front+size)%cap;
    	arr[new_rear] = x;
    	size++;
    }
    void insertFront(int x){
          if(isFull()) return;
          //+cap bcz it can be -1 on doing front-1
          front = (front+ cap -1)%cap;
          arr[front] = x;
          size++;
    }
    void deleteRear(){
    	if(isEmpty()) return;
    	else size--;
    }

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
}