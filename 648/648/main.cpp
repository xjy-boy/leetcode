#include<iostream>
#include<vector>

using namespace std;

struct TrieNode
{
    bool isWord;
    TrieNode* child[26] = { nullptr };
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

    string getRoot(string word) {
        string ans = "";
        TrieNode* p = root;
        for (char c : word)
        {
            if (p->isWord)
            {
                break;
            }
            else if (p->child[c - 'a'] == nullptr)
            {
                return "";
            }
            else
            {
                ans += c;
                p = p->child[c - 'a'];
            }
        }
        return ans;
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string root : dictionary)
        {
            trie.insert(root);
        }

        string ans = "";
        int index = 0;
        while (index < sentence.size())
        {
            string word = "";
            while (index < sentence.size() && sentence[index] != ' ')
            {
                word += sentence[index];
                index += 1;
            }
            string root = trie.getRoot(word);
            if (root.empty())
            {
                ans += word + " ";
            }
            else
            {
                ans += root + " ";
            }
            index += 1;
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
    vector<string> dict = {
        "cat","bat","rat"
    };
    string sentence = "the cattle was rattled by the battery";
    Solution s;
    cout << s.replaceWords(dict, sentence) << endl;
}