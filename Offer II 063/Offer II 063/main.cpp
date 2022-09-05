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

    string getRoot(string word)
    {
        TrieNode* p = root;
        string result = "";
        for (char c : word)
        {
            if (p->isWord)
            {
                return result;
            }
            if (p->child[c - 'a'] == nullptr)
            {
                return "";
            }
            else
            {
                p = p->child[c - 'a'];
                result += c;
            }
        }
    }
};


class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for (string s : dictionary)
        {
            t.insert(s);
        }
        int start = 0;
        int end = 0;
        while (end < sentence.size())
        {
            while (end < sentence.size() && sentence[end] != ' ')
            {
                end += 1;
            }
            string result = t.getRoot(sentence.substr(start, end - start));
            if (result == "")
            {
                end += 1;
                start = end;
            }
            else
            {
                sentence.replace(start, end - start, result);
                start += result.size() + 1;
                end = start;
            }
        }
        return sentence;
    }
};

int main()
{
    vector<string> dictionary = { "cat","bat","rat" };
    string sentence = "the cattle was rattled by the battery";
    Solution s;
    cout << s.replaceWords(dictionary, sentence) << endl;
}