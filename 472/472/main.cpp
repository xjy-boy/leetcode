#include<iostream>
#include<vector>
#include<stack>

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
public:
    TrieNode* root;
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

    bool isConnect(const string & word)
    {
        stack<TrieNode*> searchStack;
        stack<int> indexStack;
        TrieNode* p = root;
        int index = 0;
        //��ͷ��ʼ��������������ĳ��ǰ׺ʱ,����ǰ�ڵ��Լ�index��ջ
        //������������Ҳû��������ǰ׺ʱ����ջ���գ����ջ����ջ��������ʧ��
        while (true)
        {
            while (p && index < word.size())
            {
                if (p->child[word[index] - 'a'])
                {
                    p = p->child[word[index] - 'a'];
                    index += 1;
                    if (p->isWord)
                    {
                        break;
                    }
                }
                else
                {
                    p = nullptr;
                    index = word.size();
                    break;
                }
            }
            //��������
            if (index == word.size())
            {
                //�������ɹ�
                if (p && p->isWord)
                {
                    //��ջ���գ�����֮ǰ�Ѿ���ǰ׺��
                    if (!searchStack.empty())
                    {
                        return true;
                    }
                    //��ջ�գ���������ʧ��
                    else
                    {
                        return false;
                    }
                }
                //����ʧ�ܣ���ʱ��Ҫ��ջ
                else
                {
                    if (searchStack.empty())
                    {
                        return false;
                    }
                    else
                    {
                        p = searchStack.top();
                        index = indexStack.top();
                        searchStack.pop();
                        indexStack.pop();
                    }
                }
            }
            //��������ǰ׺������Ϣ��ջ
            else
            {
                searchStack.push(p);
                indexStack.push(index);
                p = root;
            }
        }
    }
};


class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie t;
        for (const string& s : words)
        {
            t.insert(s);
        }

        vector<string> ans;
        for (const string& s : words)
        {
            if (t.isConnect(s))
            {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<string> words = {
        "cat","dog","catdog","catcats"
    };
    s.findAllConcatenatedWordsInADict(words);
}