#include<iostream>
using namespace std;

class TrieNode {
public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;
    
    TrieNode(char c) {
        this->ch = c;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
    }

    TrieNode() : TrieNode(' ') {} // Default constructor for root
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(); // Initialize the root node
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
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
