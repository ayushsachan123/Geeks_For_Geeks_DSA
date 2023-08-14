#include<bits/stdc++.h>

using namespace std;

struct Stack{
	queue<int>q1,q2;
	int top(){
		return q1.front();
	}
	int size(){
		return q1.size();
	}
	int pop(){
		int ans = q1.front();
		q1.pop();
		return ans;
	}
	void push(int x){
		while(q1.empty() == false){
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(x);
		while(q2.empty() == false){
			q1.push(q2.front());
			q2.pop();
		}
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
}  