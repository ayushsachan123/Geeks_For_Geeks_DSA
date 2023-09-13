#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &height, int index, vector<int> &dp) {

	if (index == 0) return 0;
	if (dp[index] != -1) return dp[index];

	int  left = solve(height, index - 1, dp) + abs(height[index] - height[index - 1]);
	int  right = INT_MAX;
	if (index > 1)
		right = solve(height, index - 2, dp) + abs(height[index] - height[index - 2]);

	return dp[index] = min(left, right);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>height = {10, 20, 30, 10};
	int n = height.size();
	int index = n - 1;
	vector<int>dp(n + 1, -1);
	cout << solve(height, index, dp) << endl;

	return 0;
}