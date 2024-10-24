#include<iostream>
using namespace std;
class stack {
    public:
    int *arr;
    int size;
    int top;
    stack(int s) {
        this->size = s;
        arr = new int(size);
        top = -1;
    }
    void push(int element) {
        if (size - top > 1) {
            arr[top] = element;
        }
        else {
            cout << "Stack overflow" << endl;
        }
    }
    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
        }
        else {
            top--;
        }
    }
    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }
    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }

    }
 };