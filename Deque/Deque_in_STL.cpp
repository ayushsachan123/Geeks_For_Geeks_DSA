#include<bits/stdc++.h>

using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

deque<int>dq = {10,20,30};
dq.push_front(5);
dq.push_back(50);

for(auto x : dq){
	cout<<x<<" ";
}
cout<<endl;
cout<<dq.front()<<" "<<dq.back(); 

return 0;
} 