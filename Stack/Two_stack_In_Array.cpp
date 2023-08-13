#include<bits/stdc++.h>

using namespace std;

//Time Complexity - o(1)
struct TwoStacks{
	int *arr,cap,top1,top2;
	TwoStacks(int n){
		cap = n;
		top1 = -1;
		top2 = cap;
		arr = new int[n];
	}
	void push(int x){
		top1++;
		arr[top1] = x;
	}
	void push2(int x){
		if(top1 < top2 -1){
			top2--;
			arr[top2] = x;
		}
	}
	int pop1(){
		if(top1>=0){
			int x = arr[top1];
			top1--;
			return x;
		}
		else{
			exit(1);
		}
	}
	int pop2(){
		if(top2 < cap){
			int x = arr[top2];
			top2++;
			return x;
		}
		else{
			exit(1);
		}
	}
	int size1(){
		return top1;
	}
	int size2(){
		return (cap - top2);
	}
}; 

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 