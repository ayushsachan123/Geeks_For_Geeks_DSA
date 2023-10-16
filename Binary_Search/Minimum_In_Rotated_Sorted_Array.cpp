#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>&nums, int low, int high, int &ans) {
	if (low > high) {
		return;
	}
	int mid = low + (high - low) / 2;
	if (nums[low] <= nums[high]) {
		ans = min(ans, nums[low]);
		return;
	}
	if (nums[low] <= nums[mid]) {
		ans = min(ans, nums[low]);
		return solve(nums, mid + 1, high, ans);
	}
	else {
		ans = min(ans, nums[mid]);
		return solve(nums, low, mid - 1, ans);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {3, 4, 5, 1, 2};
	int n = nums.size();
	int low = 0;
	int high = n - 1;
	int ans = INT_MAX;

	solve(nums, low, high, ans);

	cout << ans << endl;

	return 0;
}