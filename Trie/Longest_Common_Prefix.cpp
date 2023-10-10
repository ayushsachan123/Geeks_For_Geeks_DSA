#include<bits/stdc++.h>

using namespace std;

//for traversing all character of first string
string longestCommonPrefix(vector<String> &arr, int n) {
	string ans = "";

	for (int i = 0; i < arr[0].length(); i++) {
		char ch = arr[0][i];

		bool match = true;

		//For comapairing ch with reat of the strings
		for (int j = 1 ; j < n; j++) {
			//not matched
			if (arr[j].size() < i || ch != arr[j][i]) {
				match false;
				break;
			}
		}

		if (match == false)
			break;

		else
			ans.push_back(ch);
	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}