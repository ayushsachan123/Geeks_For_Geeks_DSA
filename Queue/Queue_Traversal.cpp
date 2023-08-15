#include<bits/stdc++.h>

using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

queue<int>q;

q.push(10);
q.push(20);
q.push(30);

//Size of Queue
cout<<"Size "<<q.size()<<endl;

//Queue Traversal
while(q.empty() == false){
	cout<<q.front()<<" "<<q.back()<<"| ";
	q.pop();
}

return 0;
} 