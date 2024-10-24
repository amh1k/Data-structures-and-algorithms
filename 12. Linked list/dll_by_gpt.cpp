#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        this->data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node*& head, Node*& tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL) {
        cout << "Position out of bounds\n";
        return;
    }

    if (temp->next == NULL) {
        insertAtTail(head, tail, d);
    } else {
        Node* nodeToInsert = new Node(d);
        nodeToInsert->next = temp->next;
        nodeToInsert->prev = temp;
        temp->next->prev = nodeToInsert;
        temp->next = nodeToInsert;
    }
}

void deleteAtPosition(Node*& head, Node*& tail, int pos) {
    if (head == NULL) {
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL; // If the list becomes empty
        }
        delete temp;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;

    while (cnt < pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    if (curr == NULL) {
        cout << "Position out of bounds\n";
        return;
    }

    prev->next = curr->next;

    if (curr->next != NULL) {
        curr->next->prev = prev;
    } else {
        tail = prev; // Update tail if we are deleting the last node
    }

    delete curr;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtPosition(head, tail, 3, 25);

    printList(head);

    deleteAtPosition(head, tail, 1);
    printList(head);

    deleteAtPosition(head, tail, 3);
    printList(head);

    deleteAtPosition(head, tail, 5);
    printList(head);

    return 0;
}
