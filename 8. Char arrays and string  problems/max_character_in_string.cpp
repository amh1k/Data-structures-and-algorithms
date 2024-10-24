#include<iostream>
using namespace std;
char maxCharacterInString(string s) {
    int arr[26] {};
    int number = 0;
    for (int i = 0; i < s.size(); i++) {
        number = s[i] - 'a';
        arr[number]++;

    }
    int max = -1; int ans = -1;
    for (int i = 0; i < 26; i++) {
        if (arr[i] > max) {
            max = arr[i];
            ans = i;
        }

    }
    return ans + 'a';
}
int main() {
    string s = "testsample";
    cout << "Max character is " << maxCharacterInString(s);
}