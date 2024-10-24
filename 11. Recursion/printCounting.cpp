#include<iostream>
using namespace std;

//will print backwards
void printCounting(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    printCounting(n - 1);
}

//will print forwards
void printCounting(int n) {
    if (n == 0) {
        return;
    }
    printCounting(n - 1);
    cout << n << endl;
    
}