#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int target, int low, int high, int ans) {
	if (low > high) {
		return ans;
	}

	int mid = low + (high - low) / 2;

	if (nums[mid] >= target) {
		ans = mid;
		return  solve(nums, target, low, mid - 1, ans);
	}
	return  solve(nums, target, mid + 1, high, ans);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {1, 3, 5, 6};
	int target = 5;
	int n = nums.size();
	int low = 0;
	int high = n - 1;
	int ans = n;
	cout << solve(nums, target, low, high, ans);

	return 0;
}