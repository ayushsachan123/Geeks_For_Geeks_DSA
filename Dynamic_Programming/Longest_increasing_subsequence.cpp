#include<bits/stdc++.h>

using namespace std;

//Recursion
int rec(int ind, vector<int>&nums, int prev_index, int n) {
	if (ind == n) return 0;

	//Not pick
	int len = 0 + rec(ind + 1, nums, prev_index, n);
	//pick
	if (prev_index == -1 || nums[ind] > nums[prev_index])
		len =  max(len, 1 + rec(ind + 1, nums, ind, n));

	return len;
}

//Memoization
int memo(int ind, vector<int>&nums, int prev_index, int n, vector<vector<int>>&dp) {
	if (ind == n) return 0;
	if (dp[ind][prev_index + 1] != -1) return dp[ind][prev_index + 1];
	//Not pick
	int len = 0 + memo(ind + 1, nums, prev_index, n, dp);
	//pick
	if (prev_index == -1 || nums[ind] > nums[prev_index])
		len =  max(len, 1 + memo(ind + 1, nums, ind, n, dp));

	return dp[ind][prev_index + 1] = len;
}

//Tabulation
int tab(vector<int>&nums, int n) {
	//we do n+1, bcz below we are using ind+1
	vector < vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	//As everything is initialize with 0 so doen't need to write base case

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind --) {
			int len = 0 + dp[ind + 1][prev_ind + 1];

			if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
				len =  max(len, 1 + dp[ind + 1][ind + 1]);
			}
			dp[ind][prev_ind + 1] = len;
		}
	}

	return dp[0][-1 + 1];
}

//Space optimization
int space(vector<int>&nums, int n) {
	vector<int>next(n + 1, 0), cur(n + 1, 0);
	for (int ind = n - 1; ind >= 0; ind--) {
		for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind --) {
			int len = 0 + next[prev_ind + 1];

			if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
				len =  max(len, 1 + next[ind + 1]);
			}
			cur[prev_ind + 1] = len;
		}

		next = cur;
	}

	return next[-1 + 1];
}

//Optimizing tabulation Approach
int optimize(vector<int>&nums, int n) {
	vector<int> dp(n, 1);
	int maxi = 1;

	for (int i = 0; i < n; i++) {
		for (int prev = 0; prev < i; prev ++) {
			if (nums[prev] < nums[i]) {
				dp[i] = max(dp[i], 1 + dp[prev]);
			}
		}
		maxi = max(maxi, dp[i]);
	}

	return maxi;
}

//Printing LIS
int printingLIS(vector<int>& nums, int n) {
	vector<int> dp(n, 1), hash(n);
	int maxi = 1;
	int lastIndex = 0;

	for (int i = 0; i < n; i++) {
		hash[i] = i;
		for (int prev = 0; prev < i; prev ++) {
			if (nums[prev] < nums[i] &&  1 +  dp[prev] > dp[i]) {
				dp[i] = 1 +  dp[prev];
				hash[i] = prev;
			}
		}
		if (dp[i] > maxi) {
			maxi = dp[i];
			lastIndex = i;
		}
	}
	vector<int>temp;
	temp.push_back(nums[lastIndex]);
	while (hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		temp.push_back(nums[lastIndex]);
	}

	reverse(temp.begin(), temp.end());
	for (auto it : temp) {
		cout << it << " ";
	}
	cout << endl;

	return maxi;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	int n = nums.size();
	int prev_index = -1;

//Recursion
	int index = 0;
	cout << rec(index, nums, prev_index, n) << endl;

//Memoization
	vector<vector<int>>dp(n, vector<int>(n + 1, -1));
	cout << memo(index, nums, prev_index, n, dp) << endl;

//Tabulation
	cout << tab(nums, n) << endl;

//Space optimization
	cout << space(nums, n) << endl;

//Optimize
	cout << optimize(nums, n) << endl;

//Printing LIS
	cout << printingLIS(nums, n) << endl;
	return 0;
}