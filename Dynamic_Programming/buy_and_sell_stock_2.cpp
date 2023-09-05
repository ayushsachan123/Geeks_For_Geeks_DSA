#include<bits/stdc++.h>

using namespace std;

//Recursion
int rec(int ind, int buy, vector<int>&prices, int n) {
	if (ind == n) return 0;

	int profit = 0;
	if (buy) {
		profit = max(-prices[ind] + rec(ind + 1, 0, prices, n), 0 + rec(ind + 1, 1, prices, n));
	}
	else {
		profit = max(prices[ind] + rec(ind + 1, 1, prices, n), 0 + rec(ind + 1, 0, prices, n));
	}

	return profit;
}

//Memoization
int memo(int ind, int buy, vector<int>&prices, int n, vector<vector<int>>&dp) {
	if (ind == n) return 0;

	if (dp[ind][buy] != -1) return dp[ind][buy];
	int profit = 0;
	if (buy) {
		profit = max(-prices[ind] + memo(ind + 1, 0, prices, n, dp), 0 + memo(ind + 1, 1, prices, n, dp));
	}
	else {
		profit = max(prices[ind] + memo(ind + 1, 1, prices, n, dp), 0 + memo(ind + 1, 0, prices, n, dp));
	}

	return dp[ind][buy] = profit;
}

//Tabulation
int tab(int ind, int buy, vector<int>&prices, int n) {
	vector<vector<int>>dp(n + 1, vector<int>(2, 0));
	dp[n][0] = dp[n][1] = 0;

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			int profit = 0;
			if (buy) {
				profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
			}
			else {
				profit = max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
			}

			dp[ind][buy] = profit;
		}
	}
	//bcz we are operating loop in reverse order
	return dp[0][1];
}

//Space optimization
int space(int ind, int buy, vector<int>&prices, int n) {
	vector<int> ahead(2, 0), cur(2, 0);
	ahead[0] = ahead[1] = 0;

	for (int ind = n - 1; ind >= 0; ind--) {
		for (int buy = 0; buy <= 1; buy++) {
			int profit = 0;
			if (buy) {
				profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
			}
			else {
				profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
			}

			cur[buy] = profit;
		}
		ahead = cur;
	}

	return ahead[1];
}

//Further space optimization using four variable
int Fspace(int ind, int buy, vector<int>&prices, int n) {
	int aheadNotBuy, aheadBuy, curNotBuy, curBuy;
	aheadNotBuy = aheadBuy = 0;

	for (int ind = n - 1; ind >= 0; ind--) {

		curNotBuy = max(prices[ind] + aheadBuy, 0 + aheadNotBuy);

		curBuy = max(-prices[ind] + aheadNotBuy, 0 + aheadBuy);

		aheadBuy = curBuy;
		aheadNotBuy = curNotBuy;
	}

	return aheadBuy;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>prices = {7, 1, 5, 3, 6, 4};
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

//Further space optimization
	cout << Fspace(index, buy, prices, n) << endl;

	return 0;
}