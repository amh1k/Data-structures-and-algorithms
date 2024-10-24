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
void insertAtTail(ListNode* &head, ListNode* &tail, int digit) {
    ListNode* temp = new ListNode(digit);
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;

    }
    else {
        tail->next = temp;
        tail = temp;

    }
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        int carry = 0;
        while (head1 != NULL || head2 != NULL ||  carry != 0) {
            int val1 = 0;
            if (head1 != NULL) {
                val1 = head1->val;
            }
            int val2 = 0;
            if (head2 != NULL) {
                val2 = head2->val;
            }
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            insertAtTail(ansHead, ansTail, digit);
            if (head1 != NULL) {
                head1 = head1->next;
            }
            if (head2 != NULL) {
                head2 = head2->next;
            }
        }
        return ansHead;
        
    }
};