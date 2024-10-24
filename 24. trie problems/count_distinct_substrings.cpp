//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

class Node {
    public:
    Node* links[26];
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
    
};
class TrieNode {
    public:
    Node* root;
    TrieNode() {
        root = new Node();
    }
    void insert(string word, int &cnt) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            for (int j = i; j < word.size(); j++) {
                char ch = word[j];
                if (node->links[ch - 'a'] == NULL) {
                    node->links[ch - 'a'] = new Node();
                    cnt++;
                }
                node = node->links[ch - 'a'];
            }
            node = root;
        }
    }
};
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    int cnt = 0;
    TrieNode trie;
    trie.insert(s, cnt);
    return cnt + 1;
    //Your code here
}