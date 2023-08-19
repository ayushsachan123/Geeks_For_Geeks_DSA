#include<bits/stdc++.h>

using namespace std;

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i;
	int right = 2 * i + 1;

//1 based indexing so put equal sign
	if (left <= n && arr[largest] < arr[left]) {
		largest = left;
	}

	if (right <= n && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);
	}

}

void heapSort(int arr[], int n) {
	int size = n;
	while (size > 1) {
		//Step 1: swap
		swap(arr[size], arr[1]);
		size--;

		//Step 2
		heapify(arr, size, 1);
	}

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[6] = { -1, 54, 53, 55, 52, 50};
	int n = 5;
	for (int i = n / 2; i > 0; i--) {
		heapify(arr, n, i);
	}

	cout << "printing the sorted array " << endl;
	for (int i = 0; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	heapSort(arr, n);

	cout << "printing the array now " << endl;
	for (int i = 0; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}