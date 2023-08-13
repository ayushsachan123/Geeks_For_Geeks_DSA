#include<bits/stdc++.h>

using namespace std;

//Naive Solution Time Complexity - O(n^2)
void printSpan(int arr[], int n){
	for(int i=0;i<n;i++){
		int span =1;
		for(int j = i-1;j>=0 && arr[j] <= arr[i];j--){
			span++;
		}
		cout<<"span "<<span<<endl;
	}
}

//Efficient Solution
void printSpanS(int arr[], int n){
	stack<int> s;
	s.push(0);
	cout<<"span "<<1<<endl;

	for(int i=1;i<n;i++){
		int span = 1;
		while(s.empty() == false && arr[s.top()] <= arr[i]){
			s.pop();
		}
		if(s.empty() == true){
            span = i+1;
		}
		else{
			span = i-s.top();
		}
		cout<<"span "<<span<<endl;

		s.push(i);
	}
}
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int arr[] = {30,20,25,28,27,29};
int n = sizeof(arr)/sizeof(arr[0]);

//Naive Solution
printSpan(arr,n);
cout<<endl;

//Efficient Solution Using Stack
printSpanS(arr,n);

return 0;
} 