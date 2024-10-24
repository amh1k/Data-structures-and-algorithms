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
  ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr != NULL ) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

    }
    return prev;
  }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == NULL) {
            return head;
        }
        ListNode* tempHead = head;
        int count = 1;
        // ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (count < left) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        ListNode* beforeLeft = prev;
        ListNode* leftNode = curr;
        ListNode* rightNode = leftNode;
        
        while (count < right) {
           rightNode = rightNode->next;
            count++;
        }

        ListNode* afterNode = rightNode->next;
        rightNode->next = NULL;
        
        ListNode* reverseHead = reverse(leftNode);
        if (beforeLeft != NULL) {
            beforeLeft->next = reverseHead;
            head = tempHead;;
        }
        else {
            head = reverseHead;
        }
        leftNode->next = afterNode;
        return head;
        
        


        
    }
};