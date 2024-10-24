#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node * next;
    Node * prev;
    Node(int d) {
        this->data = d;
        next = NULL;
        prev = NULL;
    }
    void insertAtHead(Node *&head, int d) {
        Node * temp = new Node(d);
        if (head == NULL) {
            Node * temp = new Node(d);
            head = temp;
        }
        else {
            temp->next = head;
        head->prev = temp;
        head = temp;

        }
        
        
    }
    void insertAtTail(Node* &tail, int d) {
        Node * temp = new Node(d);
        if (tail == NULL) {
            
            tail = temp;

        }
        else {
            
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {
        int cnt = 1;
        if (pos == 1) {
            insertAtHead(head, d);
            if (tail == NULL) {
                tail = head;
                
            }
            return;
        }
        
        else {
            Node * temp = head;
            while (cnt < pos - 1) {
                temp = temp->next;
                cnt++;
            }
            if (temp->next == NULL) {
                insertAtTail(tail, d);
                return;

            }
            else {
                Node * nodeToInsert = new Node(d);
                nodeToInsert->next = temp->next;
                temp->next = nodeToInsert;
                temp->next->prev = nodeToInsert;
                nodeToInsert->prev = temp;

            }
        }
    }
    void deleteAtPosition(Node* &head, Node* &tail, int pos) {
        if (pos == 1)  {
            Node * temp = head;
            if (head == NULL) return;
            temp->next->prev = NULL;
            head = temp->next;
            temp->next = NULL;
            return;

            
        }
        else {
            Node * curr = head;
            Node * prev = NULL;
            int cnt = 1;
            while (cnt < pos) {
                prev = curr;
                curr = curr->next;
                cnt++;

            }
            if (curr->next != NULL) {
                curr->next->prev = prev;
                prev->next = curr->next;
            curr->prev = NULL;
            delete curr;
            }
            else {
                prev->next = NULL;
                curr->prev = NULL;
                tail = prev;
                delete curr;
                
            }

            
            

            curr->next = NULL;
            
        }

    }
 };