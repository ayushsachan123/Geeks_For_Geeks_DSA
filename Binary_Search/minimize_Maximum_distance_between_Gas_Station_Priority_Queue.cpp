#include<bits/stdc++.h>

using namespace std;

long double minimizeMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i], i});
    }
    for(int gasStations = 1;gasStations <= k; gasStations++){
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double inDiff = arr[secInd +1] - arr[secInd];
        long double newSecLen = inDiff / ((long double)(howMany[secInd]+1));
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}

int main() {
    vector<int>v = {1,2,3,4,5,6,7};
    int k = 6;
	cout<<minimizeMaxDistance(v, k);
	return 0;
}