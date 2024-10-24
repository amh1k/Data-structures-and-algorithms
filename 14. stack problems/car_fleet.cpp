#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0;
        
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[position[i]] = speed[i];
        }
        
        
        sort(position.begin(), position.end());
        
        int fleets = 0;
        double t1 = (double)(target - position[n - 1]) / mp[position[n - 1]]; 
        
        
        for (int i = n - 2; i >= 0; i--) {
            double t2 = (double)(target - position[i]) / mp[position[i]]; // 
            
            if (t2 > t1) { 
                
                fleets++;
                t1 = t2; 
            }
           
        }
        
        
        fleets++;
        
        return fleets;
    }
};
