#include<iostream>
using namespace std;
bool isValid(char ch) {
    if((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ) {
        return true;
    }
    else {
        return false;
    }
}
char toLower(char c) {
    if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9' ) {
        return c;
    }
    else {
        char temp = c - 'A' + 'a';
        return temp;
    }
}
 bool checkPalindrome(string s) {
    int start = 0, e = s.size() - 1;
    while (start <= e) {
        if (toLower(s[start]) != toLower(s[e])) {
            return false;
        }
        else {
            start++;
            e--;
        }
    }
    return true;
}
bool isPalindrome(string s) {
    //Remove uncessary characters
    string temp;
    for (int i =0; i < s.length(); i++) {
        if(isValid(s[i])) {
            temp.push_back(s[i]);
        }
    }
    //Converting to lowercase
    for (int i = 0; i < temp.size(); i++) {
        temp[i] = toLower(temp[i]);
    }
   checkPalindrome(temp);
}