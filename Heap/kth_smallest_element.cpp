#include<bits/stdc++.h>

using namespace std;

int kthsmallest(vector<int>arr, int k) {
	priority_queue<int>maxi;
	for (int i = 0; i < arr.size(); i++) {
		if (maxi.size() < k)
			maxi.push(arr[i]);
		else {
			if (maxi.top() > arr[i]) {
				maxi.pop();
				maxi.push(arr[i]);
			}
		}
	}
	return maxi.top();
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}