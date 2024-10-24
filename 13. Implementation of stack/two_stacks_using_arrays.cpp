#include<iostream>
using namespace std;
class twoStack {
    public:
    int * arr;
    int size;
    int top1;
    int top2;
    twoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = size;
        arr = new int(size);

    }
    void push1(int element) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = element;

        }
        else {
            cout << "Stack overflow" << endl;
        }

    }
    void push2(int element) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = element;

        }
        else {
            cout << "Stack overflow" << endl;
        }

    }
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else {
            cout << "Stack is empty" << endl;
        }
    }
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else {
            cout << "Stack is empty" << endl;
        }

    }
 };