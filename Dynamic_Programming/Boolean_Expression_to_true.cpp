#include<bits/stdc++.h>

using namespace std;

int mod = 10000007;

long long rec(int i, int j, int isTrue, string &exp) {
	if (i > j) return 0;
	if (i == j) {
		if (isTrue) {
			return exp[i] == 'T';
		}
		else {
			return exp[i] == 'F';
		}
	}

	long long ways  = 0;
	for (int ind = i + 1; ind <= j - 1; ind += 2) {
		long long lT = rec(i, ind - 1, 1, exp);
		long long lF = rec(i, ind - 1, 0, exp);
		long long rT = rec(ind + 1, j, 1, exp);
		long long rF = rec(ind + 1, j, 0, exp);

		if (exp[i] == '&') {
			if (isTrue) ways = (ways + (rT + lT) % mod) % mod;
			else ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
		}
		else if (exp[i] == '|') {
			if (isTrue) {
				ways = (ways + (lT * rT) % mod + (lT + rF) % mod + (lF + rT) % mod) % mod;
			}
			else {
				ways = (ways + (lF * rF) % mod) % mod;
			}
		}
		else {
			if (isTrue) {
				ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
			}
			else {
				ways = (ways + (lT * rT) % mod + (lF + rF) % mod) % mod;
			}
		}
	}

	return ways;
}

//Memoization
long long memo(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>>&dp) {
	if (i > j) return 0;
	if (i == j) {
		if (isTrue) {
			return exp[i] == 'T';
		}
		else {
			return exp[i] == 'F';
		}
	}

	if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

	long long ways  = 0;
	for (int ind = i + 1; ind <= j - 1; ind += 2) {
		long long lT = memo(i, ind - 1, 1, exp, dp);
		long long lF = memo(i, ind - 1, 0, exp, dp);
		long long rT = memo(ind + 1, j, 1, exp, dp);
		long long rF = memo(ind + 1, j, 0, exp, dp);

		if (exp[i] == '&') {
			if (isTrue) ways = (ways + (rT + lT) % mod) % mod;
			else ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
		}
		else if (exp[i] == '|') {
			if (isTrue) {
				ways = (ways + (lT * rT) % mod + (lT + rF) % mod + (lF + rT) % mod) % mod;
			}
			else {
				ways = (ways + (lF * rF) % mod) % mod;
			}
		}
		else {
			if (isTrue) {
				ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
			}
			else {
				ways = (ways + (lT * rT) % mod + (lF + rF) % mod) % mod;
			}
		}
	}

	return dp[i][j][isTrue] = ways;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string exp = "&(|(f))";
	int n = exp.size();
	int i = 0;
	int j = n - 1;

//Recursive
	cout << rec(i, j, 1, exp) << endl;

//Memoization
	vector<vector<vector<long long>>>dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
	cout << memo(i, j, 1, exp, dp) << endl;
	return 0;
}