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

	int n = 7;
	int x = 3;
	vector<int>arr = {1, 1, 1, 2, 2, 3, 3};

	int ans = -1;
	int low = 0;
	int high = n - 1;
	int a = lowerBound(arr, x, low, high, ans);
	if (a == -1 || arr[a] != x) {
		cout << 0 << endl;
	}
	ans = n;
	int b = upperBound(arr, x, low, high, ans);
	cout << b - a << endl;

	return 0;
}