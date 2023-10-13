#include<bits/stdc++.h>

using namespace std;

int recur(int i, int j) {
	if (i == 0 && j == 0)
		return 1;
	if (i < 0 || j < 0)
		return 0;

	int up = recur(i - 1, j);
	int left = recur(i, j - 1);

	return up + left;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m = 3;
	int n = 7;

//Recursive
	cout << recur(m - 1, n - 1);

//Memoization
	cout << memo(m - 1, n - 1);
	return 0;
}