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
ListNode*  reverse(ListNode* head)  {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* curr= head;
    ListNode* prev = NULL;
    while (curr != NULL) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
ListNode* getMiddle(ListNode* head) {
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast != NULL &&  fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

    }
    return slow;
} 
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head;
        ListNode* middle = getMiddle(head);
        ListNode* next = middle->next;
         ListNode* head2 = reverse(next);
         while (head2 != NULL) {
            if (head->val != head2->val) {
                return false;
            }
            else {
                head2 = head2->next;
                head = head->next;
            }
         }
         return true;

        
    }
};
 