#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class SinglyLL
{
public:
    Node *head;
    Node *tail;
    SinglyLL()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    void insertAtAnyPosition(int pos, int val)
    {
        Node *newNode = new Node(val);
        Node *curr = head;
        Node *prev = NULL;
        for (int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
    void deleteAtTail()
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = NULL;
        delete curr;
    }
    void deleteAtHead()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
};
Node *getPosition(SinglyLL ll, int n)
{
    Node *curr = ll.head;
    int cnt = 0;
    while (curr != NULL && cnt < n)
    {
        curr = curr->next;
        cnt++;
    }
    return curr;
}
void insertionSort(SinglyLL &ll, int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = getPosition(ll, i)->data;
        int j = i - 1;
        while (j >= 0 && getPosition(ll, j)->data >= key)
        {
            getPosition(ll, j)->data = getPosition(ll, j + 1)->data;
            j -= 1;
        }
        Node *insert = getPosition(ll, j + 1);
        insert->data = key;
    }
}