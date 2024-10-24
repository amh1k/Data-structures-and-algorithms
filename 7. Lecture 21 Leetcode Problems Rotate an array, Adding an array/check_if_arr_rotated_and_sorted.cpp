#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[(i - 1 + n )% n]  > nums[i]) {
                count ++;
            }
        }
        return count <= 1;
        
    }
};
