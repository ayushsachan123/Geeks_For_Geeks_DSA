#include<bits/stdc++.h>

using namespace std;

int rec(int i, int j, vector<int>&cuts) {
	if (i > j) return 0;

	int mini = INT_MAX;
	for (int ind = i; ind <= j; ind++) {
		int cost = cuts[j + 1] - cuts[i - 1] + rec(i, ind - 1, cuts) + rec(ind + 1, j, cuts);
		mini = min(mini, cost);
	}

	return mini;
}

//Memoization
int memo(int i, int j, vector<int>&cuts, vector<vector<int>>&dp) {
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	int mini = INT_MAX;
	for (int ind = i; ind <= j; ind++) {
		int cost = cuts[j + 1] - cuts[i - 1] + memo(i, ind - 1, cuts, dp) + memo(ind + 1, j, cuts, dp);
		mini = min(mini, cost);
	}

	return dp[i][j] = mini;
}

//Tabulation
int tab(int c, vector<int>& cuts) {
	vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

	for (int i = c; i >= 1; i--) {
		for (int j = 1; j <= c; j++) {
			if (i > j) continue;

			int mini = INT_MAX;

			for (int ind = i; ind <= j; ind++) {
				// Calculate the cost for making a cut at position 'ind'.
				int ans = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];

				mini = min(mini, ans);
			}

			dp[i][j] = mini;
		}
	}

	return dp[1][c];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>cuts = {1, 3, 4, 5};
	int len = 7; //length of the rod
	int n = cuts.size();
	cuts.insert(cuts.begin(), 0);
	cuts.push_back(len);
	sort(cuts.begin(), cuts.end());

//Recursive
	int i = 1, j = n;
	cout << rec(i, j, cuts) << endl;

//Memoization
	vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
	cout << memo(i, j, cuts, dp) << endl;

//Tabulation
	cout << tab(j, cuts) << endl;

	return 0;
}