#include<bits/stdc++.h>

using namespace std;

//Recursive solution
int solve(vector<vector<int>>&points, int day, int last) {
	if (day == 0) {
		int maxi = 0;
		for (int i = 0; i <= 2; i++) {
			if (i != last) {
				maxi = max(maxi, points[0][i]);
			}
		}
		return maxi;
	}

	int maxi = 0;
	for (int i = 0; i <= 2; i++) {
		if (i != last) {
			int activity = points[day][i] + solve(points, day - 1, i);
			maxi = max(maxi, activity);
		}
	}
	return maxi;
}

//Memoization
int memo(vector < vector < int > > &points, int day, int last, vector<vector<int>>&dp) {
	if (day == 0) {
		int maxi = 0;
		for (int i = 0; i <= 2; i++) {
			if (i != last) {
				maxi = max(maxi, points[0][i]);
			}
		}

		return maxi;
	}

	if (dp[day][last] != -1) return dp[day][last];

	int maxi = 0;
	for (int i = 0; i <= 2; i++) {
		if (i != last) {
			int activity = points[day][i] + solve(points, day - 1, i);
			maxi = max(maxi, activity);
		}
	}
	return dp[day][last] = maxi;
}

//Tabulation
int tab(vector < vector < int > > &points, int n) {
	vector < vector < int > > dp(n, vector < int > (4, 0));

	dp[0][0] = max(points[0][1], points[0][2]);
	dp[0][1] = max(points[0][0], points[0][2]);
	dp[0][2] = max(points[0][0], points[0][1]);
	dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

	for (int day = 1; day < n; day++) {
		for (int last = 0; last < 4; last++) {
			dp[day][last] = 0;
			int maxi = 0;
			for (int task = 0; task < 3; task++) {
				if (task != last) {
					int point = points[day][task] + dp[day - 1][task];
					maxi = max(maxi, point);
				}
			}
			dp[day][last] = maxi;
		}
	}

	return dp[n - 1][3];
}

//Space Optimization
int space(vector < vector < int > > &points, int n) {
	vector <int > prev(4, 0);

	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

	for (int day = 1; day < n; day++) {
		vector<int> temp(4, 0);
		for (int last = 0; last < 4; last++) {
			temp[last] = 0;
			int maxi = 0;
			for (int task = 0; task < 3; task++) {
				if (task != last) {
					int point = points[day][task] + prev[task];
					maxi = max(maxi, point);
				}
			}
			temp[last] = maxi;
		}
		prev = temp;
	}

	return prev[3];
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

//Recursive
	vector < vector < int > > points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

	int n = 3; // It represent number of day as size of row of points is 3
	int last = 3; //It means no task is done bcz task can be 0,1,2
	//Day will be n-1 bcz it is zero based indexing
	cout << solve(points, n - 1, last) << endl;

//Memoization

	vector<vector<int>>dp(n, vector<int>(4, -1));
	cout << memo(points, n - 1, last, dp) << endl;

//Tabulation
	cout << tab(points, n) << endl;

//Space Optimization
	cout << space(points, n);

	return 0;
}