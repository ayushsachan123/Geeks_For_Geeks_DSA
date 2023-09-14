#include<bits/stdc++.h>

using namespace std;

//Recursive
int rec(int ind, int w, vector<int> &wt, vector<int> &val) {
	if (ind == 0) {
		if (wt[0] <= w)  return val[0];
		return 0;
	}

	int notTake = 0 + rec(ind - 1, w, wt, val);
	int take = INT_MIN;
	if (wt[ind] <= w) {
		take = val[ind] + rec(ind - 1, w - wt[ind], wt, val);
	}

	return max(take, notTake);
}

//Memoization
int memo(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>>&dp) {
	if (ind == 0) {
		if (wt[0] <= w)  return val[0];
		return 0;
	}
	if (dp[ind][w] != -1) return dp[ind][w];

	int notTake = 0 + memo(ind - 1, w, wt, val, dp);
	int take = INT_MIN;
	if (wt[ind] <= w) {
		take = val[ind] + memo(ind - 1, w - wt[ind], wt, val, dp);
	}

	return dp[ind][w] = max(take, notTake);
}

//Tabulation

int tab(int ind, int wei, vector<int> &wt, vector<int> &val, int n) {
	vector<vector<int>>dp(n, vector<int>(wei + 1, 0));
	for (int w = wt[0]; w <= wei; w++) {
		dp[0][w] = val[0];
	}

	for (ind = 1; ind < n; ind++) {
		for (int w = 0; w <= wei; w++) {
			int notTake = 0 + dp[ind - 1][w];
			int take = INT_MIN;
			if (wt[ind] <= w) {
				take = val[ind] + dp[ind - 1][w - wt[ind]];
			}

			dp[ind][w] = max(take, notTake);
		}
	}

	return dp[n - 1][wei];
}

//Space optimizaton
int space(int ind, int wei, vector<int> &wt, vector<int> &val, int n) {

	vector<int>prev(wei + 1);
	for (int w = wt[0]; w <= wei; w++) {
		prev[w] = val[0];
	}

	for (int ind = 1; ind < n; ind++) {
		vector<int>cur(wei + 1);
		for (int w = 0; w <= wei; w++) {
			int notTake = 0 + prev[w];
			int take = INT_MIN;
			if (wt[ind] <= w) {
				take = val[ind] + prev[w - wt[ind]];
			}

			cur[w] = max(take, notTake);
		}
		prev = cur;
	}

	return prev[wei];
}

//Further space optimization
int Fspace(int ind, int wei, vector<int> &wt, vector<int> &val, int n) {

	vector<int>prev(wei + 1);
	for (int w = wt[0]; w <= wei; w++) {
		prev[w] = val[0];
	}

	for (int ind = 1; ind < n; ind++) {

		for (int w = wei; w >= 0; w--) {
			int notTake = 0 + prev[w];
			int take = INT_MIN;
			if (wt[ind] <= w) {
				take = val[ind] + prev[w - wt[ind]];
			}

			prev[w] = max(take, notTake);
		}

	}

	return prev[wei];
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>weight = {4, 5, 1};
	vector<int> values = {1, 2, 3};
	int n = 3;
	int w = 4;
	int ind = n - 1;

	//Recursive
	cout << rec(ind, w, weight, values) << endl;

	//Memoization
	vector<vector<int>>dp(n, vector<int>(w + 1, -1));
	cout << memo(ind, w, weight, values, dp) << endl;

	//Tabulation
	cout << tab(ind, w, weight, values, n) << endl;

	//Space Optimization
	cout << space(ind, w, weight, values, n) << endl;

	//Further space optimization
	cout << Fspace(ind, w, weight, values, n) << endl;

	return 0;
}