#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	unordered_map<string, int>m;

	m["a"] = 1;
	m["b"] = 2;
	m["c"] = 3;
	m["d"] = 4;

//Traverse using foreach

	for (auto i : m) {
		cout << i.first << " " << i.second << endl;
	}

	cout << endl;

//Iterators
	unordered_map<string, int> :: iterator it = m.begin();
	while (it != m.end()) {
		cout << it->first << " " << it->second << endl;
		it++;
	}

	return 0;
}