#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(int i, int j, string &str) {
	while (i < j) {
		if (str[i] != str[j]) return false;
		i++;
		j--;
	}
	return true;
}

//Recursive
int rec(int i, int n, string &str) {
	if (i == n) return 0;
	int minCost = INT_MAX;
	for (int j = i; j < n; j++) {
		if (isPalindrome(i, j, str)) {
			int cost = 1 + rec(j + 1, n, str);
			minCost = min(minCost, cost);
		}
	}

	return minCost;
}

int memo(int i, int n, string &str, vector<int>&dp) {
	if (i == n) return 0;
	if (dp[i] != -1) return dp[i];
	int minCost = INT_MAX;
	for (int j = i; j < n; j++) {
		if (isPalindrome(i, j, str)) {
			int cost = 1 + memo(j + 1, n, str, dp);
			minCost = min(minCost, cost);
		}
	}

	return dp[i] = minCost;
}

int tab(int n, string &str) {
	vector<int>dp(n + 1, 0);
	//base case
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		int minCost = INT_MAX;
		for (int j = i; j < n; j++) {
			if (isPalindrome(i, j, str)) {
				int cost = 1 + dp[j + 1];
				minCost = min(minCost, cost);
			}
		}

		dp[i] = minCost;
	}

	return dp[0] - 1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "aab";
	int n = s.size();
	int i = 0;
//Recursive
	// -1 bcz our code made the partion at the end
	cout << rec(i, n, s) - 1 << endl;

//Memoization
	vector<int>dp(n, -1);
	cout << memo(i, n, s, dp) - 1 << endl;

//Tabulation
	cout << tab(n, s) << endl;

}