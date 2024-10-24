#include<iostream>
using namespace std;
class Node {
    public:
    Node* links[26];
    int countPrefix;
    int countEndsWith;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        countPrefix = 0;
        countEndsWith = 0;
    }
    

};
class TrieNode {
    public:
    Node* root;
    TrieNode() {

    }
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i  < word.size(); i++) {
            char ch = word[i];
            if (curr->links[ch - 'a'] == NULL) {
                curr->links[ch - 'a'] = new Node();
            }
           curr = curr->links[ch - 'a'];
           curr->countPrefix++;
        }
        curr->countEndsWith++;
    }
    int countStartWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (node->links[ch - 'a'] == NULL) {
                return 0;
                
            }
            node = node->links[ch - 'a'];

        }
        return node->countPrefix;

    }
    int countEndWith(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (node->links[ch - 'a'] == NULL) {
                return 0;
                
            }
            node = node->links[ch - 'a'];
        }
        return node->countEndsWith;
    }
    void erase(string word) {
        Node* node = root;
        for (int i = 0; i < 26; i++) {
            char ch = word[i];
        }

    }

};