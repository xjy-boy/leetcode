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

    //返回零表示已经有该后缀，返回-1表示没有该后缀，返回正数表示有部分该后缀，返回值表示需要增加的长度
    int endWith(string word)
    {
        TrieNode* p = root;
        int result = 0;
        for (int i = word.length() - 1; i >= 0; i--)
        {
            if (p->child[word[i] - 'a'] == nullptr)
            {
                if (result == 0)
                {
                    //  检查p是否为根节点或者是否为单词节点
                    if (p == root || !p->isWord)
                    {
                        result = -1;
                    }
                    else
                    {
                        result = i + 1;
                    }
                }
                p->isWord = false;
                p->child[word[i] - 'a'] = new TrieNode();
                p = p->child[word[i] - 'a'];
                p->isWord = true;
            }
            else
            {
                p = p->child[word[i] - 'a'];
            }
        }
        return result;
    }
};



class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int result = 0;
        Trie t;
        for (string s : words)
        {
            int r = t.endWith(s);
            if (r < 0)
            {
                r = s.length() + 1;
            }
            result += r;
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"atime", "time","btime" };
    cout << s.minimumLengthEncoding(words) << endl;
}