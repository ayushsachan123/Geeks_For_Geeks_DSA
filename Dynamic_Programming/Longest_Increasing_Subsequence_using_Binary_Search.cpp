#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>&arr, int n) {
	vector<int>temp;
	temp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (arr[i] > temp.back()) {
			temp.push_back(arr[i]);
		}
		else {
			int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
			temp[ind] = arr[i];
		}
	}

	return temp.size();
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = nums.size();
	cout << solve(nums, n) << endl;

	return 0;
}