#include<bits/stdc++.h>

using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

stack<int> s;

s.push(10);
s.push(20);
s.push(30);

cout<<s.size()<<endl;
cout<<s.top()<<endl;
s.pop();
cout<<s.top()<<endl;

//Stack Traversal
cout<<"Stack Traversal"<<endl;
while(s.empty() == false){
	cout<<s.top()<<" ";
	s.pop();
}

return 0;

} 