#include<bits/stdc++.h>

using namespace std;

class TrieNode {
public:
	char data;
	TrieNode* children[26];
	bool isTerminal;

	TrieNode(char ch) {
		data = ch;
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
public:
	TrieNode* root;

	Trie() {
		root = new TrieNode('\0'); //Initially insert NULL character
	}


	bool prefixUtil(TrieNode* root, string word) {
		//base case
		if (word.length() == 0) {
			return true;
		}

		int index = word[0] - 'a';
		TrieNode* child;

		//present
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			//absent
			return false;
		}

		return prefixUtil(child, word.substr(1));
	}

	bool startsWith(string prefix) {
		return prefixUtil(root, prefix);
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}