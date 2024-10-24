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
ListNode* findNthNode(ListNode* head, int pos)  {
    int count = 1;
    ListNode* temp = head;
    while (count < pos) {
        temp = temp->next;
        count++;

    }
    return temp;
}

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            len ++;
            tail = tail->next;
        }
        if (k % len == 0) {
            return head;
        }
        k = k % len;
        tail->next = head;
        ListNode* nthNode = findNthNode(head, len - k);
        head = nthNode->next;
        nthNode->next = NULL;
        return head;

        
    }
};