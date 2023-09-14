#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>height = {10, 30, 40, 50, 20};
	int k = 3;
	int n = height.size();
	vector<int>dp(n, -1);
	dp[0] = 0;

	for (int i = 1; i < n; i++) {
		int minSteps = INT_MAX;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				int jump =  dp[i - j] + abs(height[i] - height[i - j]);
				minSteps = min(minSteps, jump);
			}
		}
		dp[i] = minSteps;
	}
	cout << dp[n - 1] << endl;

	return 0;
}