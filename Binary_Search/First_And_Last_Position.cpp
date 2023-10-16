#include<bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>& nums, int target, int low, int high, int ans) {
	if (low > high) {
		return ans;
	}
	int mid = low + (high - low) / 2;
	if (nums[mid] >= target) {
		ans = mid;
		return lowerBound(nums, target, low, mid - 1, ans);
	}

	return lowerBound(nums, target, mid + 1, high, ans);
}

int upperBound(vector<int>& nums, int target, int low, int high, int ans) {
	if (low > high) {
		return ans;
	}
	int mid = low + (high - low) / 2;
	if (nums[mid] > target) {
		ans = mid;
		return upperBound(nums, target, low, mid - 1, ans);
	}

	return upperBound(nums, target, mid + 1, high, ans);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>nums = {5, 7, 7, 8, 8, 10};
	int target = 8;
	int n = nums.size();
	int ans = -1;
	int low = 0;
	int high = n - 1;
	int a = lowerBound(nums, target, low, high, ans);
	if (a == -1 || nums[a] != target) {
		cout << -1 << " " << -1 << endl;
	}
	ans = n;
	int b = upperBound(nums, target, low, high, ans);
	cout << a << " " << b - 1 << endl;

	return 0;
}