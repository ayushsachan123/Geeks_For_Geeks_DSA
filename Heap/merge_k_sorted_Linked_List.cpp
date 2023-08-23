#include<bits/stdc++.h>

using namespace std;

class compare {
public:
	bool operator()(Node* a, Node* b) {
		return a->data > b->data;
	}
}

Node<int>* mergeKLists(vector<int*> & listArray) {
	priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;

	int k = listArray.size();

	if (k == 0)
		return NULL;

	//step1:

	for (int i = 0; i < k; i++) {
		if (listArray[i] != NULL) {
			minHeap.push(listArray[i]);
		}
	}

	Node* head = NULL;
	Node* tail = NULL;

	while (minHeap.size() > 0) {
		Node* top = minHeap.top();
		minHeap.pop();

		if (top->next != NULL) {
			minHeap.push(top->next);
		}

		if (head == NULL) {
			//ans linked list empty
			head = top;
			tail = top;

		}
		else {
			//insert at Linked list
			tail->next = top;
			tail = top;

		}
	}

	return head;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}