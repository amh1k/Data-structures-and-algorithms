
#include<iostream>
using namespace std;
//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//Approach one
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode * forward = curr->next;
            curr->next  = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        
    }
};

//Approach 2
class Solution {
public:
void solve(ListNode* &head, ListNode* curr, ListNode* prev) {
    if (curr == NULL) {
        head = prev; 
        return;
    }
    ListNode* forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    solve(head, curr, prev);

}
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        // while (curr != NULL) {
        //     ListNode * forward = curr->next;
        //     curr->next  = prev;
        //     prev = curr;
        //     curr = forward;
        // }
        solve(head, curr, prev);
        return head;
        
    }
};

//Approach 3