
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;
    
    TrieNode(char c) {
        this->ch = c;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
        childCount = 0;
    }

    TrieNode() : TrieNode(' ') {} // Default constructor for root
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(); // Initialize the root node
    }
    Trie(char c) {
        root = new TrieNode(c);
    }

    void insertUtil(const std::string& word, TrieNode* node) {
        if (node == nullptr) {
            return;
        }
        if (word.size() == 0) {
            node->isTerminal = true;
            return;
        }
        int index = word[0] - 'a'; // Assuming we only have capital letters
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode(word[0]);
            node->childCount++;
        }
        insertUtil(word.substr(1), node->children[index]);
    }
    
    void insert(const std::string& word) {
        insertUtil(word, root);
    }

    bool searchUtil(const std::string& word, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (word.size() == 0) {
            return node->isTerminal;
        }
        int index = word[0] - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        return searchUtil(word.substr(1), node->children[index]);
    }
    
    bool search(const std::string& word) {
        return searchUtil(word, root);
    }

    bool searchPrefixUtil(const std::string& word, TrieNode* node) {
        if (node == nullptr) {
            return false;
        }
        if (word.size() == 0) {
            return true;
        }
        int index = word[0] - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        return searchPrefixUtil(word.substr(1), node->children[index]);
    }
    
    bool startsWith(const std::string& prefix) {
        return searchPrefixUtil(prefix, root);
    }
    void lcp(string str, string& ans, TrieNode* root) {
        TrieNode* temp = root;
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if (temp->childCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            }
            else {
                break;
            }
            if (temp->isTerminal == true) {
                break;
            }
        }
        
    }
};




class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie * t = new Trie('\0');
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i] == "") {
                return "";
            }
            t->insert(strs[i]);
        }
        string ans = "";
        string first = strs[0];
        t->lcp(first, ans, t->root);
        return ans;
        
    }
};