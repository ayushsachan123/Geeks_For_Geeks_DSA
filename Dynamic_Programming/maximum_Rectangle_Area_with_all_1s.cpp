#include<bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector < int > & histo) {
	stack < int > st;
	int maxA = 0;
	int n = histo.size();
	for (int i = 0; i <= n; i++) {
		while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
			int height = histo[st.top()];
			st.pop();
			int width;
			if (st.empty())
				width = i;
			else
				width = i - st.top() - 1;
			maxA = max(maxA, width * height);
		}
		st.push(i);
	}
	return maxA;
}

int solve(vector<vector<int>>&mat, int n, int m) {
	int maxArea = 0;
	vector<int> height(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) height[j]++;
			else height[j] = 0;
		}
		int area = largestRectangleArea(height);
		maxArea = max(area, maxArea);
	}

	return maxArea;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>> mat = {
		{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1},
		{1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}
	};

	int n = 4, m = 5;
	cout << solve(mat, n, m) << endl;

	return 0;
}