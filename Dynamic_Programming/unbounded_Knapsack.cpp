#include<bits/stdc++.h>

using namespace std;

//Recursive
int rec(int ind, int w, vector<int> &val, vector<int> &wt) {
	if (ind == 0) {
		return ((int)(w / wt[0])) * val[0];
	}

	int notTake = 0 + rec(ind - 1, w, val, wt);
	int take = 0;
	if (wt[ind] <= w) {
		take = val[ind] + rec(ind, w - wt[ind], val, wt);
	}

	return max(take, notTake);
}

//Memoization
int memo(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
	if (ind == 0) {
		return ((int)(w / wt[0])) * val[0];
	}

	if (dp[ind][w] != -1) return dp[ind][w];

	int notTake = 0 + memo(ind - 1, w, val, wt, dp);
	int take = 0;
	if (wt[ind] <= w) {
		take = val[ind] + memo(ind, w - wt[ind], val, wt, dp);
	}

	return dp[ind][w] = max(take, notTake);
}

//Tabulation
int tab(int ind, int wei, vector<int> &val, vector<int> &wt, int n) {
	vector<vector<int>>dp(n, vector<int>(wei + 1, 0));

	for (int w = 0; w <= wei; w++) {
		dp[0][w] = ((int)(w / wt[0])) * val[0];
	}

	for (int i = 1; i < n; i++) {
		for (int w = 0; w <= wei; w++) {
			int notTake = 0 + dp[ind - 1][w];
			int take = 0;
			if (wt[ind] <= w) {
				take = val[ind] + dp[ind][w - wt[ind]];
			}

			dp[ind][w] = max(take, notTake);
		}
	}

	return dp[n - 1][wei];
}

//Space Optimization
int space(int ind, int wei, vector<int> &val, vector<int> &wt, int n) {
	vector<int> prev(wei + 1, 0), cur(wei + 1, 0);

	for (int w = 0; w <= wei; w++) {
		prev[w] = ((int)(w / wt[0])) * val[0];
	}

	for (int i = 1; i < n; i++) {
		for (int w = 0; w <= wei; w++) {
			int notTake = 0 + prev[w];
			int take = 0;
			if (wt[ind] <= w) {
				take = val[ind] + cur[w - wt[ind]];
			}

			cur[w] = max(take, notTake);
		}

		prev = cur;
	}

	return prev[wei];
}

//Further space optimization
int Fspace(int wei, vector<int> &val, vector<int> &wt, int n) {
	vector<int> prev(wei + 1, 0);

	for (int w = 0; w <= wei; w++) {
		prev[w] = ((int)(w / wt[0])) * val[0];
	}

	for (int ind = 1; ind < n; ind++) {
		for (int w = 0; w <= wei; w++) {
			int notTake = 0 + prev[w];
			int take = 0;
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

//Recursive
	int n = 2, w = 3;
	vector<int> val = {1, 1};
	vector<int> wt = {2, 1};
	cout << rec(n - 1, w, val, wt) << endl;

//Memoization
	vector<vector<int>>dp(n, vector<int>(w + 1, -1));
	cout << memo(n - 1, w, val, wt, dp) << endl;

//Tabulation
	cout << tab(n - 1, w, val, wt, n) << endl;

//Space optimization
	cout << space(n - 1, w, val, wt, n) << endl;

//Further space optimization
	cout << Fspace(w, val, wt, n) << endl;

	return 0;
}