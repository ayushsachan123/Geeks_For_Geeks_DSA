#include<bits/stdc++.h>

using namespace std;

struct myyStack{
	vector<int> v;
	void push(int x){
		v.push_back(x);
	}
	int pop(){
		int res = v.back();
		v.pop_back();
		return res;
	}
	int size(){
		return v.size();
	}
	bool isEmpty(){
		return v.empty();
	}
	int peek(){
		return v.back();
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif



return 0;
} 