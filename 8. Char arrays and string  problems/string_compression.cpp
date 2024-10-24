#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char> &chars) {
    int i = 0, ansIndex= 0, n = chars.size();
    while ( i < n) {
        int j = i + 1;
        while (j < n && chars[i] == chars[j]) {
            j++;
        }

        chars[ansIndex++] = chars[i];
        int count = j - i;
        if (count > 1) {
            string cnt = to_string(count);
            for (int k = 0; k < cnt.size(); k++) {
                chars[ansIndex++] = cnt[k];
            }
        }
        i = j;
        
    }
    return chars.size();

}