#include<iostream>
using namespace std;
char toLower(char c) {
    if (c <= 'a' && c >= 'z') {
        return c;
    }
    else {
        char temp = c - 'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(char a[], int n) {
    int s = 0, e = n - 1;
    while (s <= e) {
        if (toLower(a[s]) != toLower(a[e])) {
            return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}
