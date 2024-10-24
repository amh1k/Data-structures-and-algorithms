#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//  * Definition for singly-linked list.
  struct Node {
      int val;
      Node *next;
      Node* random;
      Node() : val(0), next(nullptr), random(nullptr) {};
      
      Node(int x) : val(x), next(nullptr) {}
      Node(int x, Node *next) : val(x), next(next) {}
  };



  //Approach 2 Using maps
  class Solution {
public:
 void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        temp = head;
        Node* tempClone = cloneHead;

        while (temp != NULL) {
            mp[temp] = tempClone;
            temp = temp->next;
            tempClone = tempClone->next;
        }
        temp = head;
        tempClone = cloneHead;
        
        while (temp != NULL) {
            tempClone->random = mp[temp->random];
            temp = temp->next;
            tempClone = tempClone->next;
        }
        return cloneHead;
        
    }
};








//Appraoch 3 playing with pointers
class Solution {
public:
void insertAtTail(Node* &head, Node* &tail, int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        Node* originalList = head;
        Node* cloneList = cloneHead;
        while (originalList != NULL && cloneList != NULL) {
            Node* next = originalList->next;
            originalList->next = cloneList;
            originalList = next;
            next = cloneList->next;
            cloneList->next = originalList;
            cloneList = next;
            
        }
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                temp->next->random = temp->random ? temp->random->next: temp->random;
            }
            temp = temp->next->next;
        }
        originalList = head;
        cloneList = cloneHead;
        while (originalList != NULL && cloneList != NULL) {
            originalList->next = cloneList->next;
            originalList = originalList->next;
            if (originalList != NULL) {
                cloneList->next = originalList->next;
            }
            cloneList = cloneList->next;
        } 
        return cloneHead;
        
    }

};