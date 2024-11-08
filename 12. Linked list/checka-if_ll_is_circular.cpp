#include<iostream>
using namespace std;
bool isCircular(Node* head) {
    if (head == NULL) {
        return true;
    }
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return false;
    }
    if ( temp == head) {
        return true;
    }
}