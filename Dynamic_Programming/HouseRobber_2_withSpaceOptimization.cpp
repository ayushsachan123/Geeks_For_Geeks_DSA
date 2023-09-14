#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>&nums) {
	int n = nums.size();
	int prev2 = 0;
	int prev1 = nums[0];

	for (int i = 0; i < n; i++) {
		int pick = nums[i];
		if (i > 1)
			pick += prev2;

		int notPick = 0 + prev1;
		int curi = max(pick, notPick);

		prev2 = prev1;
		prev1 = curi;
	}

	return prev1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {2, 3, 2};
	int n = nums.size();
	vector<int>temp1, temp2;
	for (int i = 0; i < n; i++) {
		if (i != 0) temp1.push_back(nums[i]);
		if (i != n - 1) temp2.push_back(nums[i]);
	}

	int a = solve(temp1);
	int b = solve(temp2);

	cout << max(a, b) << endl;

	return 0;
}