#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& height, int n, int k, int index) {
	if (index == 0) {
		return 0;
	}
	int minSteps = INT_MAX;

	for (int i = 1; i <= k; i++) {
		if (index - i >= 0) {
			int jump =  solve(height, n, k, index - i) + abs(height[index] - height[index - i]);
			minSteps = min(minSteps, jump);
		}
	}

	return minSteps;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>height = {10, 30, 40, 50, 20};
	int k = 3;
	int n = height.size();
	int index = n - 1;
	int ans = solve(height, n, k, index);
	cout << ans << endl;
	return 0;
}