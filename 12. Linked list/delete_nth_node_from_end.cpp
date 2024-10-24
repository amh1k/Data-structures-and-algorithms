#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL && n == 1) {
            return NULL;
        }
        ListNode* temp = head;
        ListNode* curr = head;
        int len = 0;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        int count = 1;
        ListNode* prev = NULL;
        int target = len - n + 1;
        while (count < target) {
            prev = curr;
            curr = curr->next;
            count++;

        }
        if  (target == 1) {
            head = curr->next;
            curr->next = NULL;
            delete curr;
            return head;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        return head;

        
    }
};