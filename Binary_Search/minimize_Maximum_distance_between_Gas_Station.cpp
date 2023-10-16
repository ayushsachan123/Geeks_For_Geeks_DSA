#include<bits/stdc++.h>

using namespace std;

long double minimizeMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> howMany(n-1, 0);
    for(int gasStations = 1;gasStations <= k; gasStations++){
        long double maxSection = -1;
        int maxInd = -1;
        for(int i=0;i<n-1;i++){
            long double diff = (arr[i+1] - arr[i]);
            long double sectionLengthj = diff/((long double)(howMany[i] +1));
            if(sectionLengthj > maxSection){
                maxSection = sectionLengthj;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    long double maxAns = -1;
    for(int i=0;i<n-1;i++){
        long double diff = (arr[i+1] -arr[i]);
        long double sectionLengthj = diff/((long double)(howMany[i] + 1));
        maxAns = max(maxAns, sectionLengthj);
    }
    return maxAns;
}

int main() {
    vector<int>v = {1,2,3,4,5,6,7};
    int k = 6;
	cout<<minimizeMaxDistance(v, k);
	return 0;
}