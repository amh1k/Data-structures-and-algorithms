#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node (int d) {
        this->data = d;
        next = NULL;
    }

    void insertAtPosition(Node* &tail, int element, int data) {

        //Assuming element exists in the circular linked list
        if (tail == NULL) {
            Node * newNode = new Node(data);
            newNode->next = newNode;
            tail = newNode;
        }
        else {
            Node * curr = tail;
            while(curr->data != element) {
                curr = curr->next;
            }
            Node * temp = new Node(data);
            temp->next = curr->next;
            
            curr->next = temp;
        }
    }
    void printList(Node* tail) {
        Node * temp = tail;
        do {
            cout << tail->data;
            tail = tail->next;
        }
        while(tail->next != temp);

    }
    void deleteNode(Node* &tail ,int d) {
        if (tail == NULL) {
            return;
        }
        else {
            Node * prev = tail;
            Node * curr = prev->next;
            while (curr-> data != d) {
                prev = curr;
                curr = curr->next;
            
            }
            if (curr == prev) {
                tail = NULL;
                return;
            }
            if (tail == curr) {
                tail = prev;

            }
            prev->next = prev->next;
            curr->next = NULL;
            delete curr;

        }

    }
};