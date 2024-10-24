#include<iostream>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
ListNode* solve(ListNode* first, ListNode* second) {
    if (first->next == NULL) {
        first->next = second;
        return first;
    }
    ListNode* curr1 = first;
    ListNode* next1 = first->next;
    ListNode* curr2 = second;
    while (next1 != NULL && curr2 != NULL) {
        if (curr2->val >= curr1->val && curr2->val <= next1->val) {
            curr1->next = curr2;
            ListNode* next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
            
            

        }
        else {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        ListNode* firstHead = list1;
        ListNode* secondHead = list2;
        if (firstHead->val <= secondHead->val) {
            return solve(firstHead, secondHead);
        }
        else {
            return solve(secondHead, firstHead);
        }
        
    }
};