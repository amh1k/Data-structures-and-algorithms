#include<iostream>
#include<stack>
#include<vector>
using namespace std;



class MinStack {
public:
   stack<long long>s;
   long long min;
   
    MinStack() {
        
        
    }
    
    void push(int val) {
        long long valC = static_cast<long long>(val);
        if (s.empty()) {
            s.push(valC);
            min = valC;
        } else {
            if (valC < min) {
                s.push(2 * valC - min);
                min = valC;
            } else {
                s.push(valC);
            }
        }
    }

    void pop() {
        if (s.empty()) {
            return;
        }
        long long curr = s.top();
        if (curr > min) {
            s.pop();
        } else {
            min = 2 * min - curr;
            s.pop();
        }
    }

    int top() {
        if (s.empty()) {
            return -1;  
        }
        long long curr = s.top();
        if (curr < min) {
            return static_cast<int>(min);
        } else {
            return static_cast<int>(curr);
        }
    }

    int getMin() {
        return static_cast<int>(min);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */