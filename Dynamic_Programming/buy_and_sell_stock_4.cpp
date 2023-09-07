#include<bits/stdc++.h>

using namespace std;

//Recursion
int rec(int ind, int transNo, vector<int>&prices, int n, int k) {
	if (ind == n || transNo == 2 * k) return 0;

	if (transNo % 2 == 0) { //buy
		return max(-prices[ind] + rec(ind + 1, transNo + 1, prices, n, k), 0 + rec(ind + 1, transNo, prices, n, k));
	}
	//sell
	return max(prices[ind] + rec(ind + 1, transNo + 1, prices, n, k), 0 + rec(ind + 1, transNo, prices, n, k));

}

//Memoization
int memo(int ind, int transNo, vector<int>&prices, int n, int k, vector<vector<int>>&dp) {
	if (ind == n || transNo == 2 * k) return 0;

	if (dp[ind][transNo] != -1) return dp[ind][transNo];

	if (transNo % 2 == 0) { //buy
		return dp[ind][transNo] = max(-prices[ind] + memo(ind + 1, transNo + 1, prices, n, k, dp), 0 + memo(ind + 1, transNo, prices, n, k, dp));
	}
	//sell
	return dp[ind][transNo] = max(prices[ind] + memo(ind + 1, transNo + 1, prices, n, k, dp), 0 + memo(ind + 1, transNo, prices, n, k, dp));

}

//Tabulation
int tab(int ind, vector<int>&prices, int n, int k) {
	vector<vector<int>>dp(n + 1, vector<int>(2 * k + 1, 0));
	//n+1 bcz we are accessing ind+1

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int transNo = 2 * k - 1; transNo >= 0; transNo--) {
			if (transNo % 2 == 0) { //buy
				dp[ind][transNo] = max(-prices[ind] + dp[ind + 1][transNo + 1], 0 + dp[ind + 1][transNo]);
			}
			else
				dp[ind][transNo] = max(prices[ind] + dp[ind + 1][transNo + 1], 0 + dp[ind + 1][transNo]);
		}
	}

	return dp[0][0];
}

//Space optimization
int space(int ind, vector<int>&prices, int n, int k) {
	vector<int>after(2 * k + 1, 0);
	vector<int>cur(2 * k + 1, 0);

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int transNo = 2 * k - 1; transNo >= 0; transNo--) {
			if (transNo % 2 == 0) { //buy
				cur[transNo] = max(-prices[ind] + after[transNo + 1], 0 + after[transNo]);
			}
			else
				cur[transNo] = max(prices[ind] + after[transNo + 1], 0 + after[transNo]);
		}
		after = cur;
	}

	return after[0];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>prices = {2, 4, 1};
	int n = prices.size();
//Recursion
	int index = 0;
	int k = 2;
	int transNo = 0;
	cout << rec(index, transNo, prices, n, k) << endl;

//Memoization
	vector<vector<int>>dp(n, vector<int>(2 * k , -1));
	cout << memo(index, transNo, prices, n, k, dp) << endl;

//Tabulation
	cout << tab(index, prices, n, k) << endl;

//Space optimization
	cout << space(index, prices, n, k) << endl;

	return 0;
}