#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible( vector<int>&stalls, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i]- lastPos >= mid) {
            cowCount++;
            if (cowCount == k) {
                return true;
            }
            lastPos = stalls[i];
        }

    }
    return false;
    
}
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int ans = -1;
    int s = 0, e = stalls.size() - 1, mid = s + (e - s) / 2;
    while (s <= e) {
        if (isPossible(stalls, k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}