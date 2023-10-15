#include<bits/stdc++.h>

using namespace std;

bool BinarySearch(int *arr, int s, int e, int target) {

	//Element not found
	if (s > e)
		return false;

	int mid = s + (e - s) / 2;

	//Element found
	if (arr[mid] == target)
		return true;

	if (arr[mid] < target) {
		return BinarySearch(arr, mid + 1, e, target);
	}
	else {
		return BinarySearch(arr, s, mid - 1, target);
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[5] = {2, 4, 6, 8, 9};
	int size = 5;
	int target = 4;
	int s = 0;
	bool ans = BinarySearch(arr, s, size - 1, target);

	if (ans)
		cout << "Element Found";
	else
		cout << "Element not found";


	return 0;
}