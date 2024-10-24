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
  ListNode* reverse(ListNode* temp) {
    ListNode* curr = temp;
    ListNode* prev = NULL;
    while (curr != NULL) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;

  }
  ListNode* getKthNode(ListNode* head, int k) {
    int count = 1;
    while (head != NULL && count < k) {
        head = head->next;
        count++;
    }
    return head;


  }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while (temp != NULL) {
            ListNode* kthNode = getKthNode(temp, k);
            if (kthNode == NULL) {
                if (prevLast) {
                    prevLast->next = temp;
                }
                break;
            }
            else {
                ListNode* nextNode = kthNode->next;
                kthNode->next = NULL;
                reverse(temp);
                if (temp == head) {
                    head = kthNode;
                }
                else {
                    prevLast->next = kthNode;
                }
                prevLast = temp;
                temp = nextNode;
            }


        }
        return head;
        
    }
};