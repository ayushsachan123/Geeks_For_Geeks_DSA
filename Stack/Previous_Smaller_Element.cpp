#include<bits/stdc++.h>

using namespace std;


void prevS(int arr[], int n){
	stack<int> s;
	s.push(arr[0]);
	cout<<-1<<" ";

	for(int i=1;i<n;i++){
	
		while(s.empty() == false && s.top() > arr[i]){
			s.pop();
		}
		if(s.empty() == true){
			cout<<-1<<" ";
		}
		else{
			cout<<s.top()<<" ";
		}

		s.push(arr[i]);
	}
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int arr[] = {15,10,18,12,4,6,2,8};
int n = sizeof(arr)/sizeof(arr[0]);

prevS(arr,n);


return 0;
} 