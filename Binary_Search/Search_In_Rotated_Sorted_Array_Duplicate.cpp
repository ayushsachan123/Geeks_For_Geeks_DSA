#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int>& nums, int &target, int low, int high) {
	if (low > high) {
		return 0;
	}
	int mid = low + (high - low) / 2;
	if (nums[mid] == target) {
		return 1;
	}

	//condition for duplicates
	if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
		return  solve(nums, target, low + 1, high - 1);

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

	vector<int>nums = {2, 5, 6, 0, 0, 1, 2};
	int target = 0;
	int n = nums.size();
	int low = 0;
	int high = n - 1;
	cout << solve(nums, target, low, high);

	return 0;
}