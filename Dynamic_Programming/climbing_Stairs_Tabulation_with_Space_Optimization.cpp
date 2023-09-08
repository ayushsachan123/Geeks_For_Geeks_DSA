#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 2;

	if (n <= 1)
		return n;
//similar to fibonacci but prev2 = 1
	int prev2 = 1;
	int prev1 = 1;
	for (int i = 2; i <= n; i++) {
		int curi = prev1 + prev2;
		prev2 = prev1;
		prev1 = curi;
	}

	cout << prev1 << endl;

	return 0;
}