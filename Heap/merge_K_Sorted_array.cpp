#include<bits/stdc++.h>

using namespace std;

class node {
public:
	int data;
	int row;
	int col;

	node(int data, int row, int col) {
		this->data = data;
		this->row = row;
		this->col = col;
	}
};

class compare {
public:
	bool operator()(node* a, node* b) {
		return a->data > b->data;
	}
};

vector<int> mergeSortedArrays(vector<vector<int>>&kArrays, int k) {
	//writing own comperator compare
	priority_queue<node*, vector<node*>, compare> minHeap;

	//step1: Insert first element of all array
	for (int i = 0; i < k; i++) {
		node* tmp = new node(kArrays[i][0], i, 0);
		minHeap.push(tmp);
	}

	vector<int>ans;

	//step2:
	while (minHeap.size() > 0) {
		node* tmp = minHeap.top();

		ans.push_back(tmp->data);
		minHeap.pop();

		int i = tmp->row;
		int j = tmp->col;

		if (j + 1 < kArrays[i].size()) {
			node* next = new node(kArrays[i][j + 1], i, j + 1);
			minHeap.push(next);
		}
	}
	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>>arr = {{1},
		{2},
		{3},
		{3, 5, 9},
		{4},
		{1, 2, 3, 8}
	};

	mergeSortedArrays(arr,)
	return 0;
}