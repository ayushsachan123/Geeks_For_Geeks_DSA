#include<bits/stdc++.h>

using namespace std;

//Iterative
void reverse(queue<int>&q){
	stack<int>s;
	while(q.empty() ==false){
		s.push(q.front());
		q.pop();
	}
	while(s.empty() == false){
		q.push(s.top());
		s.pop();
	}
}

//Recursive

void reverseR(queue<int>&q){
	if(q.empty()) return;
	int a = q.front();
	q.pop();
	reverse(q);
	q.push(a);
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

queue<int>q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);

// reverse(q);

reverseR(q);
while(q.empty() == false){
	cout<<q.front()<<" ";
	q.pop();
}

return 0;
} 