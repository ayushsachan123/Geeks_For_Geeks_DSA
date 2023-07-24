#include<bits/stdc++.h>

using namespace std;

int getMaxArea(int arr[], int n){
	stack<int>s;
	int res = 0;
	for(int i=0;i<n;i++){
		while(s.empty() == false && arr[s.top()] >=arr[i]){
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

int maxRectangle(int arr[4][4]){
	//First find the area of first row
	int res = getMaxArea(arr[0],4);
	for(int i=1;i<4;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j] == 1){
				arr[i][j] +=arr[i-1][j];
			}
		}
		res = max(res,getMaxArea(arr[i],4)); 
	}
	return res;
}

int main(){
	
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

int arr[4][4] = {{0,1,1,0},
               {1,1,1,1},
               {1,1,1,1},
               {1,1,0,0}};

int ans  = maxRectangle(arr);
cout<<ans<<endl;

return 0;
}  