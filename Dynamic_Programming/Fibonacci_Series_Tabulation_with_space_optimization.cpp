#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int prev2 = 0;
	int prev1 = 1;
	for (int i = 2; i <= n; i++) {
		int curi = prev1 + prev2;
		prev2 = prev1;
		prev1 = curi;
	}

	cout << prev1 << endl;

	return 0;
}