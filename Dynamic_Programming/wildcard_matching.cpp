// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

#include<bits/stdc++.h>

using namespace std;

//Recursion
bool rec(int i, int j, string s1, string s2) {
	if (i < 0 && j < 0) return true;
	if (i < 0 && j >= 0) return false;
	if (j < 0 && i >= 0) {
		for (int ii = 0; ii <= i; ii++) {
			if (s1[ii] != '*') return false;
		}
		return true;
	}

	if (s1[i] == s2[j] || s1[i] == '?')
		return rec(i - 1, j - 1, s1, s2);

	if (s1[i] == '*')
		return rec(i - 1, j, s1, s2) | rec(i, j - 1, s1, s2);

	return false;

}

//Memoization
bool memo(int i, int j, string s1, string s2, vector<vector<int>>&dp) {
	if (i < 0 && j < 0) return true;
	if (i < 0 && j >= 0) return false;
	if (j < 0 && i >= 0) {
		for (int ii = 0; ii <= i; ii++) {
			if (s1[ii] != '*') return false;
		}
		return true;
	}

	if (dp[i][j] != -1) return dp[i][j];

	if (s1[i] == s2[j] || s1[i] == '?')
		return dp[i][j] = memo(i - 1, j - 1, s1, s2, dp);

	if (s1[i] == '*')
		return dp[i][j] = memo(i - 1, j, s1, s2, dp) | memo(i, j - 1, s1, s2, dp);

	return dp[i][j] = false;
}

//Tabulation
bool tab(int n, int m, string s1, string s2) {
	vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
	dp[0][0] = true;
	for (int j = 1; j <= m; j++) {
		dp[0][j] = false;
	}

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int ii = 1; ii <= i; ii++) {
			if (s1[ii - 1] != '*') {
				flag = false;
				break;
			}
		}
		//for every row we are assinging the 0th column's value
		dp[i][0] = flag;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
				dp[i][j] = dp[i - 1][j - 1];

			else if (s1[i - 1] == '*')
				dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
			else
				dp[i][j] = false;
		}
	}

	return dp[n][m];
}

//Space optimization
bool space(int n, int m, string s1, string s2) {
	vector<bool>prev(m + 1, false), cur(m + 1, false);
	prev[0] = true;
	for (int j = 1; j <= m; j++) {
		prev[j] = false;
	}

	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int ii = 1; ii <= i; ii++) {
			if (s1[ii - 1] != '*') {
				flag = false;
				break;
			}
		}
		//for every row we are assinging the 0th column's value
		cur[0] = flag;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
				cur[j] = prev[j - 1];

			else if (s1[i - 1] == '*')
				cur[j] = prev[j] | prev[j - 1];
			else
				cur[j] = false;
		}
		prev = cur;
	}

	return prev[m];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1 = "aa";
	string s2 = "a";
	int n = s1.size();
	int m = s2.size();

//Recursion
	cout << rec(n - 1, m - 1, s1, s2) << endl;

//Memoization
	vector < vector<int>>dp(n, vector<int>(m, -1));
	cout << memo(n - 1, m - 1, s1, s2, dp) << endl;

//Tabulation
	cout << tab(n, m, s1, s2) << endl;

//Space optimization
	cout << space(n, m, s1, s2) << endl;

	return 0;
}