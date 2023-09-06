#include<bits/stdc++.h>

using namespace std;

//Recursion
int rec(int ind, int buy, vector<int>&prices, int n, int cap) {
	if (ind == n || cap == 0) return 0;

	if (buy) {
		return max(-prices[ind] + rec(ind + 1, 0, prices, n, cap), 0 + rec(ind + 1, 1, prices, n, cap));
	}

	return max(prices[ind] + rec(ind + 1, 1, prices, n, cap - 1), 0 + rec(ind + 1, 0, prices, n, cap));

}

//Memoization
int memo(int ind, int buy, vector<int>&prices, int n, int cap, vector<vector<vector<int>>>&dp) {
	if (ind == n || cap == 0) return 0;
	if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

	if (buy) {
		return dp[ind][buy][cap] = max(-prices[ind] + rec(ind + 1, 0, prices, n, cap), 0 + rec(ind + 1, 1, prices, n, cap));
	}

	return dp[ind][buy][cap] = max(prices[ind] + rec(ind + 1, 1, prices, n, cap - 1), 0 + rec(ind + 1, 0, prices, n, cap));
}

//Tabulation
int tab(int ind, int buy, vector<int>&prices, int n, int cap) {
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

	//As we see all the values in dp is 0 so not necessary to write base case
	for (ind = 0; ind < n; ind++) {
		for (int buy = 0; buy <= 1; buy++) {
			dp[ind][buy][0] = 0;
		}
	}

	for (int buy = 0; buy <= 1; buy++) {
		for (int cap = 0; cap < 2; cap++) {
			dp[n][buy][cap] = 0;
		}
	}

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			//for every cap = 0 value is zero so not necessary to compute this that's why cap start from 1
			for (int cap = 1; cap <= 2; cap++) {
				if (buy) {
					dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], 0 + dp[ind + 1][1][cap]);
				}
				else
					dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], 0 + dp[ind + 1][0][cap]);
			}
		}
	}
	return dp[0][1][2];

}

//Space optimization
int space(int ind, int buy, vector<int>&prices, int n, int cap) {
	vector<vector<int>>after(2, vector<int>(3, 0));
	vector<vector<int>>cur(2, vector<int>(3, 0));

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			//for every cap = 0 value is zero so not necessary to compute this that's why cap start from 1
			for (int cap = 1; cap <= 2; cap++) {
				if (buy) {
					cur[buy][cap] = max(-prices[ind] + after[0][cap], 0 + after[1][cap]);
				}
				else
					cur[buy][cap] = max(prices[ind] + after[1][cap - 1], 0 + after[0][cap]);
			}
		}
		after = cur;
	}
	return after[1][2];

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>prices = {3, 3, 5, 0, 0, 3, 1, 4};
	int n = prices.size();
	int buy = 1;
//Recursion
	int index = 0;
	int cap = 2;
	cout << rec(index, buy, prices, n, cap) << endl;

//Memoization
	vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
	cout << memo(index, buy, prices, n, cap, dp) << endl;

//Tabulation
	cout << tab(index, buy, prices, n, cap) << endl;

//Space optimization
	cout << space(index, buy, prices, n, cap) << endl;

	return 0;
}