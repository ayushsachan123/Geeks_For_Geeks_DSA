#include<bits/stdc++.h>

using namespace std;

//Enqueue o(1)  Dequeue o(n)
//Here size is current size & cap is the total size of array

struct Queue{
	int size, cap;
	int *arr;

	Queue(int c){
		cap = c;
		size = 0;
		arr = new int[cap];
	}
	bool isFull(){
		return (size == cap);
	}
	bool isEmpty(){
		return (size == 0);
	}
	void enqueue(int x){
        if(isFull()) return;
        arr[size] = x;
        size++; 
	}
	void dequeue(){
		for(int i=0;i<size-1;i++){
			arr[i] = arr[i+1];
		}
		size--;
	}
	int getFront(){
		if(isEmpty()) return -1;
		else return 0;
	}
	int getRear(){
		if(isEmpty()) return -1;
		else return size-1;
	}

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 