#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        int n = prerequisites.size();
        vector<int>indegree(numCourses, 0);
        for (int i = 0; i < n; i++) {
            int course = prerequisites[i][0];
            int preq = prerequisites[i][1];
           adj[preq].push_back(course);

        }
        for (int i = 0; i < numCourses; i++) {
            for (auto it: adj[i]) {
                indegree[it] ++;
            }
        }
        queue<int>q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int>topo;
        while (!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            for (auto it: adj[node]) {
                indegree[it] --;
                if (indegree[it] == 0) q.push(it);
            }

        }
        if (topo.size() == numCourses) return true;
        else return false;
        
    }
};