#include<bits/stdc++.h>

using namespace std;

//Recursive
int rec(int i, int j, vector<int>nums) {
	if (i > j) return 0;
	int maxi = INT_MIN;
	for (int ind = i; ind <= j; ind++) {
		int cost = nums[i - 1] * nums[ind] * nums[j + 1] + rec(i, ind - 1, nums) + rec(ind + 1, j, nums);
		maxi = max(maxi, cost);
	}

	return maxi;
}

//Memoization
int memo(int i, int j, vector<int>&nums, vector<vector<int>>&dp) {
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int maxi = INT_MIN;
	for (int ind = i; ind <= j; ind++) {
		int cost = nums[i - 1] * nums[ind] * nums[j + 1] + memo(i, ind - 1, nums, dp) + memo(ind + 1, j, nums, dp);
		maxi = max(maxi, cost);
	}

	return dp[i][j] = maxi;
}

int tab(int n, vector<int>&nums) {
	vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= n; j++) {
			if (i > j) continue;
			int maxi = INT_MIN;
			for (int ind = i; ind <= j; ind++) {
				int cost = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
				maxi = max(maxi, cost);
			}

			dp[i][j] = maxi;
		}
	}

	return dp[1][n];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {3, 1, 5, 8};
	int n = nums.size();
	nums.push_back(1);
	nums.insert(nums.begin(), 1);

//Recursive
	int i = 1, j = n;
	cout << rec(i, j, nums) << endl;

//Memoization
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	cout << memo(i, j, nums, dp) << endl;

//Tabulation
	cout << tab(j, nums) << endl;

	return 0;
}