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

cout<<q.front()<<" "<<q.back()<<endl;

q.pop();
cout<<q.front()<<" "<<q.back()<<endl;

return 0;
} 