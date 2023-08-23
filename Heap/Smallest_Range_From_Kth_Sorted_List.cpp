#include<bits/stdc++.h>

using namespace std;

class node {
	int data;
	int row;
	int col;
	node(int d, int r, int c) {
		data = d;
		row = r;
		col = c;
	}
};

class compare {
public:
	bool operator()(node* a, node* b)
	return a->data > b->data;
};

int kSorted(vector<vector<int>> &a, int k, int n) {
	int mini = INT_MAX, maxi = INT_MINI;
	priority_queue<node*, vector<node*>, compare> minHeap;


//Step 1: create a min Heap for starting element of each list and tracking mini/maxi value
	for (int i = 0; i < k; i++) {
		int element = a[i][0];
		mini = min(mini, element);
		maxi = max(maxi, element);
		minHeap.push(element, i, 0);
	}

	int start = mini, end = maxi;

	//Process ranges
	while (!minHeap.empty()) {

		//mini fetch
		node *temp = minHeap.top();
		minHeap.pop();
		mini = temp->data;

		//range or answer updation
		if (maxi - min < end - start) {
			start = mini;
			end = maxi;
		}
		//next element exists
		if (temp->col + 1 < n) {
			maxi = max(maxi, a[temp.row][temp.col + 1]);
			minHeap.push(new node(a[temp.row][temp.col + 1], temp->row, temp->col + 1));
		}
		else {
			//next element does not exist
			break;
		}
	}

	//returning the difference of range values
	return (end - start + 1);
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}