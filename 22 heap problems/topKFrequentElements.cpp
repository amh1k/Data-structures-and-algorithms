#include<bits/stdc++.h>
using namespace std;


class Compare {
    public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;

    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for (auto i: nums) {
            mp[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare>pq;
        for (auto i : mp) {
            pq.push({i.first, i.second});


        }
        int count = 0;
        vector<int>ans;
        while (count < k) {
            int el = pq.top().first;
            pq.pop();
            ans.push_back(el);
            count++;

        }
        return ans;

        
    }
};