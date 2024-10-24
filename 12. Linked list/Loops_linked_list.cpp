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
ListNode* intersectionPoint(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
         while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                return slow;
            }
        }
        
        return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* intersection = intersectionPoint(head);
        if (intersection == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        while (slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
        
    }
    ListNode* removeLopp(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* startingNode = detectCycle(head);
    if (startingNode == NULL) {
        return head;
    }
    ListNode* temp = startingNode;
    while (temp->next != startingNode) {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
};
