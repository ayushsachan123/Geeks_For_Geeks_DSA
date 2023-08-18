#include<bits/stdc++.h>

using namespace std;


void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

	if (left < n && arr[largest] < arr[left]) {
		largest = left;
	}

	if (right < n && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[8] = { -1, 4, 7, 9, 11, 14, 19, 17};
	int n = 7;
	for (int i = n / 2; i > 0; i--) {
		heapify(arr, n, i);
	}

	cout << "printing the array now " << endl;
	for (int i = 0; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}