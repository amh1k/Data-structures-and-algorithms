#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums) {
    int nonZero =  0;
    for (int i = 0; i < nums.size(); i++ ) {
        swap(nums[i], nums[nonZero++]);
    }
}