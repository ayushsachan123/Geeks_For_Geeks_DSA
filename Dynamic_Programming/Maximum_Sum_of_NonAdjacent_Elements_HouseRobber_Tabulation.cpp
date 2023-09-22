#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {1, 2, 3, 1};
	int n = nums.size();
	vector<int>dp(n, -1);

	dp[0] = nums[0];
	int neg = 0;

	for (int i = 0; i < n; i++) {
		int pick = nums[i];
		if (i > 1)
			pick += dp[i - 2];

		int notPick = 0 + dp[i - 1];

		dp[i] = max(pick, notPick);
	}
	cout << dp[n - 1] << endl;

	return 0;
}