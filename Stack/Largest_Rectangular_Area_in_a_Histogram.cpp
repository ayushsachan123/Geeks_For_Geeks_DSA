#include<bits/stdc++.h>

using namespace std;

//Naive Solution Time Complexity - O(n^2)
int getMaxArea(int arr[], int n){
	int res =0;
	for(int i=0;i<n;i++){
		int curr = arr[i];
		for(int j = i-1;j>=0;j--){
			if(arr[j]>=arr[i]) curr +=arr[i];
			else  break;
		}
		for(int j=i+1;j<n;j++){
			if(arr[j]>=arr[i]) curr +=arr[i];
			else  break;
		}
		res = max(res,curr);
	}
	return res;
}

//Efficient Solution Time Complexity o(n)
int getMaxAreaE(int arr[], int n){
	stack<int>s;
	int res = 0;
	for(int i=0;i<n;i++){
		while(s.empty() == false && arr[s.top()] >= arr[i]){
			int tp = s.top();
			s.pop();
			int curr;
			if(s.empty() == true){
				curr = arr[tp]*i;
			}
			else{
				curr = arr[tp]*(i-s.top()-1);
			}
			res = max(res,curr);
		}
		s.push(i);
	}
 while(s.empty() == false){
 	int tp = s.top();
 	s.pop();
 	int curr;
 	 if(s.empty() == true){
				curr = arr[tp]*n;
	}
	else{
	   curr = arr[tp]*(n-s.top()-1);
	}
	res = max(res,curr);
 }
 return res;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int arr[] = {6,2,5,4,1,5,6};
int n = sizeof(arr)/sizeof(arr[0]);
int ans = getMaxAreaE(arr,n);
cout<<ans<<endl;

return 0;
} 