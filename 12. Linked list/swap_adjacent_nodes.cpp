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
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL && curr->next != NULL) {
            ListNode* first = curr;
            ListNode* second = curr->next;
            ListNode* nextPair = curr->next->next;
            second->next = first;
            first->next = nextPair;
            if (prev) {
                prev->next = second;
            }
            else {
                head = second;
            }
            prev = curr;
            curr = nextPair;
            
        }
        return head;
        
    }
};