#include<iostream>
using namespace std;
class Node {
    public:

    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
    void insertAtHead(Node *&head, int data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void insertAtTail(Node *&tail, int data) {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }
    void insertAtPosition(Node *&head, Node *&tail,int position, int d) {
        if (position == 1) {
            insertAtHead(head, d);
            return;
        }
        Node * temp = head;
        int count = 1;
        while (count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp->next == NULL) {
            insertAtTail(tail, d);
            return;
        }
        Node *insertedNode = new Node(d);
        insertedNode->next = temp->next;
        temp->next = insertedNode;
    }
    void deleteNodeAtPos(int pos, Node  *&head, Node* &tail) {
        if  (pos == 1) {
            Node * temp = head;
            head = head->next;
            temp->next = NULL;


        }
        else {
            
            Node * curr = head;
            Node * prev = NULL;
            int cnt = 1;
            while (cnt  < pos) {
                prev = curr;
                curr = curr->next;
                cnt++;
                
            }
            if (curr->next == NULL) {
                prev->next = NULL;
                tail = prev;
                delete curr;
                return;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }

    }
};
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Example usage:
    Node listOps(0); // Creating an instance to call member functions

    listOps.insertAtHead(head, 10);
    listOps.insertAtTail(tail, 20);
    listOps.insertAtPosition(head, tail, 2, 15);
    listOps.deleteNodeAtPos(2, head, tail);

    // Print the list to verify the operations
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}