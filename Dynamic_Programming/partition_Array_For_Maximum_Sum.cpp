#include<bits/stdc++.h>

using namespace std;

int rec(int ind, int n, int k, vector<int>&arr) {
	if (ind == n) return 0;
	int maxAns = 0;
	int len = 0, maxi = INT_MIN;

	for (int j = ind; j < min(n, ind + k); j++) {
		len++;
		maxi = max(maxi, arr[j]);
		int sum = len * maxi + rec(j + 1, n, k, arr);
		maxAns = max(maxAns, sum);
	}

	return maxAns;
}

//Memoization
int memo(int ind, int n, int k, vector<int>&arr, vector<int>&dp) {
	if (ind == n) return 0;
	if (dp[ind] != -1) return dp[ind];
	int maxAns = 0;
	int len = 0, maxi = INT_MIN;

	for (int j = ind; j < min(n, ind + k); j++) {
		len++;
		maxi = max(maxi, arr[j]);
		int sum = len * maxi + memo(j + 1, n, k, arr, dp);
		maxAns = max(maxAns, sum);
	}

	return dp[ind] = maxAns;
}

//Tabulation
int tab(int n, int k, vector<int>&arr) {
	vector<int>dp(n + 1, 0);
	dp[n] = 0;

	for (int ind = n - 1; ind >= 0; ind--) {
		int maxAns = 0;
		int len = 0, maxi = INT_MIN;

		for (int j = ind; j < min(n, ind + k); j++) {
			len++;
			maxi = max(maxi, arr[j]);
			int sum = len * maxi + dp[j + 1];
			maxAns = max(maxAns, sum);
		}

		dp[ind] = maxAns;
	}

	return dp[0];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;
	int n = arr.size();
	int index = 0;

//Recursion
	cout << rec(index, n, k, arr) << endl;

//Memoization
	vector<int>dp(n, -1);
	cout << memo(index, n, k, arr, dp) << endl;

//Tabulation
	cout << tab(n, k, arr) << endl;

	return 0;
}