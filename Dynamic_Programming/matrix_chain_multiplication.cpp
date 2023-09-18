#include<bits/stdc++.h>

using namespace std;

//Recursive
int rec(int i, int j, vector<int>&arr) {
	if (i == j)
		return 0;

	int mini = INT_MAX;

	for (int k = i; k <= j - 1; k++) {
		int steps = arr[i - 1] * arr[k] * arr[j] + rec(i, k, arr) + rec(k + 1, j, arr);

		mini = min(mini, steps);
	}

	return mini;
}

//Memoization
int memo(int i, int j, vector<int>&arr, vector<vector<int>>&dp) {
	if (i == j)
		return 0;

	if (dp[i][j] != -1) return dp[i][j];

	int mini = INT_MAX;

	for (int k = i; k <= j - 1; k++) {
		int steps = arr[i - 1] * arr[k] * arr[j] + memo(i, k, arr, dp) + memo(k + 1, j, arr, dp);

		mini = min(mini, steps);
	}

	return dp[i][j] = mini;
}

//Tabulation
int tab(vector<int>&arr, int n) {
	vector < vector<int>>dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		dp[i][i] = 0;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j < n; j++) {
			int mini = INT_MAX;

			for (int k = i; k <= j - 1; k++) {
				int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];

				mini = min(mini, steps);
			}
			dp[i][j] = mini;
		}
	}

	return dp[1][n - 1];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr = {40, 20, 30, 10, 30};
	int n = arr.size();

//Recursive
	int i = 1, j = n - 1;
	cout << rec(i, j, arr) << endl;

//Memoization
	vector<vector<int>>dp(n, vector<int>(n, -1));
	cout << memo(i, j, arr, dp) << endl;

//Tabulation
	cout << tab(arr, n) << endl;

	return 0;
}