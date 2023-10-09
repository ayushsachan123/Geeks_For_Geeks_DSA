#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int &target, int low, int high) {
	if (low > high) {
		return -1;
	}
	int mid = low + (high - low) / 2;
	if (nums[mid] == target) {
		return mid;
	}
	//left sorted
	if (nums[low] <= nums[mid]) {
		if (nums[low] <= target && target <= nums[mid])
			return solve(nums, target, low, mid - 1);
		else
			return solve(nums, target, mid + 1, high);
	}
	else {
		if (nums[mid] <= target && target <= nums[high])
			return solve(nums, target, mid + 1, high);
		else
			return solve(nums, target, low, mid - 1);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {4, 5, 6, 7, 0, 1, 2};
	int target = 0;
	int n = nums.size();
	int low = 0;
	int high = n - 1;
	cout << solve(nums, target, low, high) << endl;

	return 0;

}