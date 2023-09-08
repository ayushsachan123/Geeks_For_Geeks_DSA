#include<bits/stdc++.h>

using namespace std;

//Recursion
int rec(int ind, int buy, vector<int>&prices, int n) {
	//>= bcz on selling we do ind+2 so we go pot of bound from n-1
	if (ind >= n) return 0;

	int profit = 0;
	if (buy) {
		profit = max(-prices[ind] + rec(ind + 1, 0, prices, n), 0 + rec(ind + 1, 1, prices, n));
	}
	else {
		profit = max(prices[ind] + rec(ind + 2, 1, prices, n), 0 + rec(ind + 1, 0, prices, n));
	}

	return profit;
}

//Memoization
int memo(int ind, int buy, vector<int>&prices, int n, vector<vector<int>>&dp) {
	if (ind >= n) return 0;

	if (dp[ind][buy] != -1) return dp[ind][buy];
	int profit = 0;
	if (buy) {
		profit = max(-prices[ind] + memo(ind + 1, 0, prices, n, dp), 0 + memo(ind + 1, 1, prices, n, dp));
	}
	else {
		profit = max(prices[ind] + rec(ind + 2, 1, prices, n), 0 + rec(ind + 1, 0, prices, n));
	}

	return dp[ind][buy] = profit;
}

//Tabulation
int tab(int ind, int buy, vector<int>&prices, int n) {
	//dealing with n+2 so it should n+2
	vector<vector<int>>dp(n + 2, vector<int>(2, 0));
	dp[n][0] = dp[n][1] = 0;

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			int profit = 0;
			if (buy) {
				profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
			}
			else {
				profit = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
			}

			dp[ind][buy] = profit;
		}
	}
	//bcz we are operating loop in reverse order
	return dp[0][1];
}

//Space optimization
int space(int ind, int buy, vector<int>&prices, int n) {
	vector<int> front2(2, 0), front1(2, 0), cur(2, 0);


	for (int ind = n - 1; ind >= 0; ind--) {

		cur[1]  = max(-prices[ind] + front1[0], 0 + front1[1]);

		cur[0] = max(prices[ind] + front2[1], 0 + front1[0]);

		front2 = front1;

		front1 = cur;
	}

	return cur[1];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>prices = {2, 4, 1};
	int n = prices.size();
	int buy = 1;
//Recursion
	int index = 0;
	cout << rec(index, buy, prices, n) << endl;

//Memoization
	vector<vector<int>>dp(n, vector<int>(2, -1));
	cout << memo(index, buy, prices, n, dp) << endl;

//Tabulation
	cout << tab(index, buy, prices, n) << endl;

//Space optimization
	cout << space(index, buy, prices, n) << endl;

	return 0;
}