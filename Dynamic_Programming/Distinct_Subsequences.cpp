//Given two strings s and t, return the number of distinct subsequences of s which equals t.

#include<bits/stdc++.h>

using namespace std;

//Recursive
int rec(int i, int j, string s, string t) {
	if (j < 0) return 1;
	if (i < 0) return 0;

	if (s[i] == t[j]) {
		return rec(i - 1, j - 1, s, t) + rec(i - 1, j, s, t);
	}

	return rec(i - 1, j, s, t);
}

//Memoization
int memo(int i, int j, string s, string t, vector<vector<int>>&dp) {
	if (j < 0) return 1;
	if (i < 0) return 0;

	if (dp[i][j] != -1) return dp[i][j];
	if (s[i] == t[j]) {
		return dp[i][j] = memo(i - 1, j - 1, s, t, dp) + memo(i - 1, j, s, t, dp);
	}

	return dp[i][j] = memo(i - 1, j, s, t, dp);
}

//Tabulation
int tab(int n, int m, string s, string t) {
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int j = 1; j <= m; j++) {
		dp[0][j] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][m];
}

//Space optimization
int space(int n, int m, string s, string t) {
	vector<double>prev(m + 1, 0), cur(m + 1, 0);
	prev[0] = cur[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				cur[j] = prev[j - 1] + prev[j];
			}
			else
				cur[j] = prev[j];
		}
		prev = cur;
	}

	return prev[m];
}

//Further space optimization
int Fspace(int n, int m, string s, string t) {
	vector<double>prev(m + 1, 0);
	prev[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (s[i - 1] == t[j - 1]) {
				prev[j] = prev[j - 1] + prev[j];
			}
		}

	}

	return (int)prev[m];
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "rabbbit";
	string t = "rabbit";
	int n = s.size();
	int m = t.size();

	//Recursion
	cout << rec(n - 1, m - 1, s, t) << endl;
	//Memoization
	vector<vector<int>>dp(n, vector<int>(m, -1));
	cout << memo(n - 1, m - 1, s, t, dp) << endl;

	//Tabulation
	cout << tab(n, m, s, t) << endl;

	//Space optimization
	cout << space(n, m, s, t) << endl;

	//Further space optimization
	cout << Fspace(n, m, s, t) << endl;
	return 0;
}