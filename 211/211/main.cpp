#include<iostream>

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


class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
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

    bool search(string word) {
        return search(word, root,0);
    }
    bool search(string word,TrieNode *p,int index) {
        for (int i = index; i < word.size();i++)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (p->child[j] != nullptr)
                    {
                        if (search(word, p->child[j], i + 1))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            else
            {
                if (p->child[word[i] - 'a'] == nullptr)
                {
                    return false;
                }
                else
                {
                    p = p->child[word[i] - 'a'];
                }
            }
        }
        return p->isWord;
    }
};

int main()
{
    WordDictionary w;
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("mad");
    w.search("pad");
    w.search("bad");
    w.search(".ad");
    w.search("b..");
}