#include<bits/stdc++.h>

using namespace std;

//Naive Solution
//Time Complexity o(n^2)

void prevGreater(int arr[], int n){
   for(int i=0;i<n;i++){
   	 int j;
   	  for(j = i-1;j>=0;j--){
   	  	if(arr[j]>arr[i]){
   	  		cout<<arr[j]<<" ";
   	  		break;
   	  	}
   	  }
    if(j == -1){
    	cout<<-1<<" ";
    }
   }
}

//Efficient Solution
//Time Complexity o(n)
void prevGreaterE(int arr[], int n){
	stack<int> s;
	s.push(arr[0]);
	cout<<"Greater "<<-1<<endl;

	for(int i=1;i<n;i++){
	
		while(s.empty() == false && s.top() <= arr[i]){
			s.pop();
		}
		if(s.empty() == true){
			cout<<"Greater "<<-1<<endl;
		}
		else{
			cout<<"Greater "<<s.top()<<endl;
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

// prevGreater(arr,n);
// cout<<endl;
prevGreaterE(arr,n);

return 0;
} 