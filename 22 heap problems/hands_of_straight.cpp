#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int>mp;
        priority_queue<int, vector<int>, greater<int>>minHeap;
        for (auto i: hand) {
            mp[i] ++;
            if (mp[i] == 1) {
                minHeap.push(i);

            }
            
        }
        // int k = 0;
        if (hand.size() % groupSize == 0) {
           while (!minHeap.empty()) {
              int el = minHeap.top();
              
              for (int i = 0; i < groupSize; i++) {
                if (mp[el + i] == 0) {
                    return false;
                }
                mp[el + i] --;
                if (mp[el + i] == 0) {
                    if (el + i != minHeap.top()) {
                        return false;
                    }
                    minHeap.pop();
                }
               
           }



        }
        }
        else {
            return false;
        }
        return true;
        
    }
};