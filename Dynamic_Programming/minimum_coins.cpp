#include<bits/stdc++.h>

using namespace std;

//Recursion
int rec(int ind, int T, vector<int> &nums) {
	if (ind == 0) {
		if (T % nums[0] == 0) return T / nums[0];
		return 1e9;
	}

	int notTake = 0 + rec(ind - 1, T, nums);
	int take = INT_MAX;
	if (nums[ind] <= T) take = rec(ind, T - nums[ind], nums);

	return min(take, notTake);
}

//Memoization
int memo(int ind, int T, vector<int> &nums, vector<vector<int>>&dp) {
	if (ind == 0) {
		if (T % nums[0] == 0) return T / nums[0];
		return 1e9;
	}
	if (dp[ind][T] != -1) return dp[ind][T];
	int notTake = 0 + rec(ind - 1, T, nums, dp);
	int take = INT_MAX;
	if (nums[ind] <= T) take = rec(ind, T - nums[ind], nums, dp);

	return dp[ind][T] = min(take, notTake);
}

//Tabulation
int tab(int ind, int target, vector<int> &nums) {
	vector<vector<int>>dp(n, vector<int>(T + 1, 0));
	for (int T = 0; T <= target; T++) {
		if (T % nums[0] == 0) dp[0][T] = T / nums[0];
		else dp[0][T] = 1e9;
	}

	for (int ind = 1; ind < n; ind++) {
		for (int T = 0; T <= target; T++) {
			int notTake = 0 + dp[ind - 1][T];
			int take = INT_MAX;
			if (nums[ind] <= T) take = dp[ind][T];

			dp[ind][T] = min(take, notTake);
		}
	}

	return dp[n - 1][target];
}

//Space Optimization
int space(int ind, int target, vector<int> &nums) {
	vector<int>prev(target + 1, 0);
	for (int T = 0; T <= target; T++) {
		if (T % nums[0] == 0) prev[T] = T / nums[0];
		else prev[T] = 1e9;
	}

	for (int ind = 1; ind < n; ind++) {
		vector<int>cur(target + 1, 0);
		for (int T = 0; T <= target; T++) {
			int notTake = 0 + prev[T];
			int take = INT_MAX;
			if (nums[ind] <= T) take = cur[T];

			cur[T] = min(take, notTake);
		}

		prev = cur
	}

	return prev[target];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = nums.size();
	int ans = rec(n - 1, target, nums);
	if (ans > 1e9) cout << -1 << endl;
	else cout << ans << endl;

	vector<vector<int>>dp(n, vector<int>(T + 1, -1));
	memo(n - 1, target, nums, dp);

	int ans = tab(n - 1, target, nums);

	return 0;
}