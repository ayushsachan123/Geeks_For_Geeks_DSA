#include<bits/stdc++.h>

using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

//Creation
	unordered_map<string, int>m;

//Insertion 1
	pair<string, int>p = make_pair("ayush", 3);
	m.insert(p);

//Insertion 2
	pair<string, int>pair2("sachan", 2);
	m.insert(pair2);

//Insert 3
	m["mera"] = 1;
	m["mera"] = 2;

//Search
	cout << m["mera"] << endl;
	cout << m.at("ayush") << endl;

//If we access like this it will make an entry in map
	cout << m["unknownKey"] << endl;

//If we access using at then it will give error
	// cout << m.at("unknown") << endl;

//size
	cout << m.size() << endl;

//to check presence if absent -0, present - 1
	cout << m.count("bro") << endl;

//erase
	m.erase("sachan");

	return 0;
}