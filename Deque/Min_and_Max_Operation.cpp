#include<bits/stdc++.h>

using namespace std;

deque<int>dq;

void insertMin(int x){
	dq.push_front(x);
}
void insertMax(int x){
	dq.push_back(x);
}
int getMin(){
	return dq.front();
}
int getMax(){
	return dq.back();
}
int extraMin(){
	int a = getMin();
	dq.pop_front();
	return a;
}
int extraMax(){
	int a = getMax();
	dq.pop_back();
	return a;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


return 0;
} 