#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {1, 2, 3, 1};
	int n = nums.size();
	int prev2 = 0;
	int prev1 = nums[0];

	for (int i = 0; i < n; i++) {
		int pick = nums[i];
		if (i > 1)
			pick += prev2;

		int notPick = 0 + prev1;
		int curi = max(pick, notPick);

		prev2 = prev1;
		prev1 = curi;
	}
	cout << prev1 << endl;

	return 0;
}