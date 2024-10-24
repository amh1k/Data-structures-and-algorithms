#include<iostream>
using namespace std;

class TrieNode {
    public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char c) {
        this->ch = c;
        for (int i = 0; i < 26; i++  ) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }

};
class Trie {
    public:
    TrieNode* root;
    void insertUtil (string word, TrieNode* root) {
        if (word.size() == 0) {
            root->isTerminal = true;

        }
        int index = word[0] = 'A';// Assuimg we ony have cspitsl letters
        if (root->children[index] != nullptr) {

        }
        else {
            root->children[index] = new TrieNode(word[0]);
        }
        insertUtil(word.substr(1), root->children[index]);
    }
    void insertWord(string word) {
        insertUtil(word, root);
    }
    bool searchUtil(string word, TrieNode* root) {
        if (word.size() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'A';;
        TrieNode* child;
        if (root->children[index]->ch != word[0]) {
            return false;
        }
        else {
            child = root->children[index];
        }
        searchUtil(word.substr(1), child);
    }
    bool searchWord(string word) {
        searchUtil(word, root);
    }
    bool searchPrefixUtil(string word, TrieNode* root) {
         if (word.size() == 0) {
            return true;
        }
        int index = word[0] - 'A';;
        TrieNode* child;
        if (root->children[index]->ch != word[0]) {
            return false;
        }
        else {
            child = root->children[index];
        }
        searchPrefixUtil(word.substr(1), child);

    }
    bool startWith(string prefix) {
        return searchPrefixUtil(prefix, root);
    }
};