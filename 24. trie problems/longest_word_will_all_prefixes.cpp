#include<iostream>
using namespace std;
class Node {
    public:
    Node* links[26];
    bool flag;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
            flag = false;
        }
    }
};
class Trie {
    public:
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size();i++) {
            char ch = word[i];
            if (node->links[ch - 'a'] == NULL) {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }
    bool check(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++ ) {
           char  ch = word[i];
            if (node->links[ch - 'a'] == NULL) return false;
            else {
                if (node->flag = false) {
                    return false;
                }

            }
        }
        return true;
     }
};