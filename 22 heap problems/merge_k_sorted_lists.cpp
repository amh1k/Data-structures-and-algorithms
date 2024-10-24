#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;
        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            if (head == nullptr) {
                head = tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
            if (top->next != nullptr) {
                pq.push(top->next);
            }
        }
        return head;
    }
};