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

    //�������ʾ�Ѿ��иú�׺������-1��ʾû�иú�׺������������ʾ�в��ָú�׺������ֵ��ʾ��Ҫ���ӵĳ���
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
                    //  ���p�Ƿ�Ϊ���ڵ�����Ƿ�Ϊ���ʽڵ�
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