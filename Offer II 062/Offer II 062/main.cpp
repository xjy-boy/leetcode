#include<iostream>

using namespace std;


struct TrieNode
{
    bool isWord;
    TrieNode* child[26] = {nullptr};
    TrieNode() 
    {
        isWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word)
        {
            if (p->child[c - 'a'] == nullptr)
            {
                p->child[c - 'a'] = new TrieNode();
                p = p->child[c - 'a'];
            }
            else
            {
                p = p->child[c - 'a'];
            }
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (char c : word)
        {
            if (p->child[c - 'a'] == nullptr)
            {
                return false;
            }
            else
            {
                p = p->child[c - 'a'];
            }
        }
        return p->isWord;
    }
        
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix)
        {
            if (p->child[c - 'a'] == nullptr)
            {
                return false;
            }
            else
            {
                p = p->child[c - 'a'];
            }
        }
        return true;
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.search("application") << endl;
    t.insert("app");
    cout << t.search("app") << endl;
    cout << t.startsWith("apple") << endl;
    cout << t.search("apple") << endl;
}