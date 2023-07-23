#include<bits/stdc++.h>

using namespace std;

//Naive Solution
void nextGreater(int arr[], int n){
	for(int i=0;i<n;i++){
		int j;
		for(j=i+1;j<n;j++){
			if(arr[j]>arr[i]){
				cout<<arr[j]<<" ";
				break;
			}
		}
		if(j==n){
			cout<<-1<<endl;
		}
	}
}
//Efficient solution
void nextGreaterE(int arr[], int n){
	stack<int> s;
	vector<int> v;
	s.push(arr[n-1]);
	v.push_back(-1);
	for(int i=n-2;i>=0;i--){
		while(s.empty() == false && s.top()<= arr[i])
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

int arr[] = {5,15,10,8,6,12,9,18};
int n = sizeof(arr)/sizeof(arr[0]);
// nextGreater(arr,n);
// cout<<endl;
nextGreaterE(arr,n);
cout<<endl;	

return 0;
} 