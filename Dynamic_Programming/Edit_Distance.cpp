// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character Delete a character Replace a character

#include<bits/stdc++.h>

using namespace std;

//Recursive
int rec(int i, int j, string s1, string s2) {
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;

	if (s1[i] == s2[j]) return rec(i - 1, j - 1, s1, s2);
	return 1 + min(rec(i, j - 1, s1, s2), min(rec(i - 1, j, s1, s2), rec(i - 1, j - 1, s1, s2)));
}

//Memoization
int memo(int i, int j, string s1, string s2, vector<vector<int>>&dp) {
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;

	if (dp[i][j] != -1) return dp[i][j];

	if (s1[i] == s2[j]) return dp[i][j] = memo(i - 1, j - 1, s1, s2, dp);
	return dp[i][j] = 1 + min(memo(i, j - 1, s1, s2, dp), min(memo(i - 1, j, s1, s2, dp), memo(i - 1, j - 1, s1, s2, dp)));
}

//Tabulation
int tab(int n, int m, string s1, string s2) {
	vector < vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 0 ; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= m; j++) {
		dp[0][j] = j;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	}

	return dp[n][m];
}

//Space optimization
int space(int n, int m, string s1, string s2) {
	vector<int>prev(m + 1, 0), cur(m + 1, 0);

	for (int j = 0; j <= m; j++) {
		prev[j] = j;
	}

	for (int i = 1; i <= n; i++) {
		cur[0] = i;
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) cur[j] = prev[j - 1];
			else cur[j] = 1 + min(cur[j - 1], min(prev[j], prev[j - 1]));
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

	string s1 = "horse";
	string s2 = "ros";
	int n = s1.size();
	int m = s2.size();

	//Recursive
	cout << rec(n - 1, m - 1, s1, s2) << endl;

	//Memoization
	vector<vector<int>>dp(n, vector<int>(m, -1));
	cout << memo(n - 1, m - 1, s1, s2, dp) << endl;

	//Tabulation
	cout << tab(n , m , s1, s2) << endl;

	//Space optimization
	cout << space(n , m , s1, s2) << endl;

	return 0;
}