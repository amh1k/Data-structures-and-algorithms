#include<iostream>
#include<stack>
using namespace std;


void sortedInsert(stack<int> &s, int element) {
    if (s.empty() || s.top() < element) {
        s.push(element);
        return;
    }

    int temp = s.top();
    s.pop();

    sortedInsert(s, element);

    s.push(temp);
}

void SortedStack::sort() {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();

    sort();

    sortedInsert(s, temp);
}
