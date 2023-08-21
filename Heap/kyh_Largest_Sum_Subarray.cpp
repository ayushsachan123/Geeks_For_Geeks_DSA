#include<bits/stdc++.h>

using namespace std;

//Naive Solution - T.C - o(n^2logn) S.C - o(n^2)
int getKthLargest(vector<int>&arr, int k) {
	vector<int>sumStore;
	for (int i = 0; i < arr.size(); i++) {
		int sum = 0;
		for (int j = i; j < arr.size(); j++) {
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());
	return sumStore[sumStore.size() - k];

}

//Efficient Solution - T.C - o(n^2logn) S.C - o(k)

int getKthLargestE(vector<int>&arr, int k) {
	priority_queue<int, vector<int>, greater<int>>mini;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (mini.size() < k)
				mini.push(sum);

			else {
				if (sum > mini.top()) {
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> v = {1, 4, 6, 8, 3, 5};
	int k = 5;
	int ans = getKthLargest(v, k);
	cout << ans << endl;

	int ans1 = getKthLargestE(v, k);
	cout << ans1 << endl;

	return 0;
}