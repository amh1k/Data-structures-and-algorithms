#include<iostream>
using namespace std;
void reverse(string &s) {
    int start = 0, e = s.size() - 1;
    while(start < e) {
        swap(s[start++], s[e--]);
    }

}
void reverseWordInString(string &s) {
    int i = 0;
    string temp;
    string final;

    while (i < s.size()) {
        while (s[i] != ' ' &&  s[i] != '\0') {
            temp.push_back(s[i]);
            i++;
            
        }
        
        reverse(temp);
        final += temp;
        final.push_back(' ');
        temp.clear();
        i++;


    }
    s = final;
}
int main() {
    string s = "My name is";
    reverseWordInString(s);
    cout << s << endl;
 }