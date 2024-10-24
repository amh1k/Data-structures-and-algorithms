#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,  int>mp;
        priority_queue<int>maxHeap;
        queue<pair<int, int>>q;
        for (auto i: tasks) {
            mp[i]++;
        }
        for (auto i: mp) {
            maxHeap.push(i.second);
        }
        int time = 0;
        while (!maxHeap.empty() || !q.empty()) {
            time ++;
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
            if (!maxHeap.empty()) {
                int el = maxHeap.top();
            maxHeap.pop();
            if (el - 1 > 0) {
                pair<int,int>p = {el-1, time + n + 1};
                q.push(p);
            }

            }
            

        }
        return time;
        
        
    }
};