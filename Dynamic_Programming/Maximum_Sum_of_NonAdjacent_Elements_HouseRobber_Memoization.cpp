#include<bits/stdc++.h>

using namespace std;

int solve(int index, vector<int>&nums, vector<int>&dp) {
	if (index == 0) return nums[index];
	if (index < 0) return 0;
	if (dp[index] != -1) return dp[index];

	//pick
	int pick = nums[index] + solve(index - 2, nums, dp);

	//Not pick
	int notPick = 0 + solve(index - 1, nums, dp);

	return dp[index] = max(pick, notPick);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {1, 2, 3, 1};
	int n = nums.size();
	int index = n - 1;
	vector<int>dp(n, -1);
	cout << solve(index, nums, dp);

	return 0;
}