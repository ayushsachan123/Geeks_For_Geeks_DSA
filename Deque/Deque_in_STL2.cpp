#include<bits/stdc++.h>

using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

deque<int>dq = {10,15,30,5,12};

//return iterator(address) pointing to first element
auto it = dq.begin(); 
it++;

for(auto x: dq){
	cout<<x<<" ";
}
cout<<endl;

//Insert the element at position of Iterator
dq.insert(it, 20);
for(auto x: dq){
	cout<<x<<" ";
}
cout<<endl;

//Remove the first Item
dq.pop_front();
//Remove the last Item
dq.pop_back();

cout<<dq.size();

return 0;
} 