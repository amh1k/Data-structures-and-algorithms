#include<iostream>
using namespace std;
bool isPalindrome(string str, int s, int e) {
    if (s > e) {
        return;
    }
    if (str[s] != str[e]) {
        return false;
    }
    else {
        return isPalindrome(str, s + 1, e - 1);
    }
}