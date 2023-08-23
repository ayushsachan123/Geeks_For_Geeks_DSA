#include<bits/stdc++.h>

using namespace std;

struct Deque{
	int size,cap;
	int *arr;
	Deque(int c){
		cap = c;
		size =0;
		arr = new int[cap];
	}
	bool isFull(){
		return (size == cap);
	}
	bool isEmpty(){
		return (size == 0);
	}
	void insertRear(int x){
		if(isFull()) return;
		arr[size] = x;
		size++;
	}
	void deleteRear(){
		if(isEmpty()) return;
		else size--;
	}
	int getRear(){
		if(isEmpty()) return -1;
		else return arr[size-1];
	}
	void insertFront(int x){
		if(isFull()) return;
		else{
			for(int i=size-1;i>=0;i--){
				arr[i+1] = arr[i];
			}
			arr[0] = x;
			size++;
		}
	}
	void deleteFront(){
		if(isEmpty()) return;
		for(int i=0;i<size-1;i++){
			arr[i] = arr[i+1];
		}
		size--;
	}
	int getFront(){
		if(isEmpty()) return -1;
		else return arr[0];
	}

};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 