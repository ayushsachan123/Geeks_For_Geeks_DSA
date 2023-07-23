#include<bits/stdc++.h>

using namespace std;

void nextSmaller(int arr[], int n){
	stack<int> s;
	vector<int> v;
	s.push(arr[n-1]);
	v.push_back(-1);
	for(int i=n-2;i>=0;i--){
		while(s.empty() == false && s.top()> arr[i])
			s.pop();
		if(s.empty() == true)
			v.push_back(-1);
		else{
          v.push_back(s.top());
		}
		s.push(arr[i]); 
	}
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int arr[] = {8,4,6,2,3};
int n = sizeof(arr)/sizeof(arr[0]);
nextSmaller(arr,n);

return 0;
} 