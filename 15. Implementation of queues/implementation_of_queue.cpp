#include <iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int count;
    int front;
    int rear;
    int size;

    Queue(int s) {
        this->size = s;
        arr = new int[this->size];
        front = rear = count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void push(int val) {
        if (count >= size) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear % size] = val;
        rear++;
        count++;
    }

    int pop() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int val = arr[front % size];
        arr[front % size] = -1; // Optional: Just to visualize popping, not needed functionally
        front++;
        count--;
        return val;
    }

    void print() {
        if (count == 0) {
            cout << "Queue is empty, can't print" << endl;
            return;
        }
        for (int i = front; i < rear; i++) {
            cout << arr[i % size] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.print(); // should print 1 2 3 4 5

    q.pop();
    q.pop();

    q.print(); // should print 3 4 5

    q.push(6);
    q.push(7);

    q.print(); // should print 3 4 5 6 7

    q.push(8); // should print "Queue is full"

    return 0;
}
