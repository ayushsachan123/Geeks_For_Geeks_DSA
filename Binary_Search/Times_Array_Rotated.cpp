#include<bits/stdc++.h>

using namespace std;

int solve(int arr[], int n) {
	int low = 0, high = n - 1;
	int ans = INT_MAX;
	int index = -1;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[low] <= arr[high]) {
			if (arr[low] < ans) {
				index = low;
				ans = arr[low];
			}
			break;
		}


		if (arr[low] <= arr[mid]) {

			if (arr[low] < ans) {
				index = low;
				ans = arr[low];
			}


			low = mid + 1;
		}
		else {


			if (arr[mid] < ans) {
				index = mid;
				ans = arr[mid];
			}


			high = mid - 1;
		}
	}
	return index;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[5] = {5, 1, 2, 3, 4};
	int n = 5;
	cout << solve(arr, n) << endl;

	return 0;
}