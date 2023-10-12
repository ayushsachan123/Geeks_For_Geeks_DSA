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

	void insertUtil(TrieNode* root, string word) {
		//base case
		if (word.length() == 0) {
			root->isTerminal = true;
			return;
		}
		//assumption, word will be in CAPS
		int index = word[0] - 'A';
		TrieNode* child;
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			//absent
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}

		//Recursion
		insertUtil(child, word.substr(1));

	}

	void insertWord(string word) {
		insertUtil(root, word);
	}

//Search
	bool searchUtil(TrieNode* root, string word) {
		//base case
		if (word.length() == 0) {
			return root->isTerminal;
		}

		int index = word[0] - 'A';
		TrieNode* child;

		//present
		if (root->children[index] != NULL) {
			child = root->children[index];
		}
		else {
			//absent
			return false;
		}

		return searchUtil(child, word.substr(1));
	}

	bool searchWord(string word) {
		return searchUtil(root, word);
	}

	//Remove


};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Trie *t = new Trie();
	t->insertWord("ARM");
	t->insertWord("Do");
	t->insertWord("TIME");


	cout << "Present or not " << t->searchWord("TIME") << endl;

	return 0;
}