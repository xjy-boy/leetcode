#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TrieNode
{
    unordered_map<string, TrieNode*> next;
    int index;
    TrieNode(int _index)
    {
        index = _index;
    }
};


class WordFilter {
private:
    TrieNode* root = NULL;
    vector<string>& wordList;
    vector<int> allIndex;
    void insert(string& word, int index)
    {
        TrieNode* current = root;
        TrieNode* p = root;
        string t = "";
        for (int i = 0; i < word.size(); i++)
        {
            p = current;
            for (int j = i; j < word.size(); j++)
            {
                t = string({ word[j],'#' });
                if (!p->next.count(t))
                {
                    p->next[t] = new TrieNode(-1);
                }
                p = p->next[t];
                p->index = index;
            }

            p = current;
            for (int j = i; j < word.size(); j++)
            {
                t = string({ '#',word[word.size() - j - 1] });
                if (!p->next.count(t))
                {
                    p->next[t] = new TrieNode(-1);
                }
                p = p->next[t];
                p->index = index;
            }

            t = string({ word[i],word[word.size() - i - 1] });
            if (!current->next.count(t))
            {
                current->next[t] = new TrieNode(-1);
            }
            current = current->next[t];
            current->index = index;
        }
    }
public:
    WordFilter(vector<string>& words) :wordList(words){
        root = new TrieNode(-1);
        for (int i = 0; i < wordList.size(); i++)
        {
            insert(wordList[i], i);
        }
    }

    int f(string pref, string suff) {
        if (pref.size() < suff.size())
        {
            pref += string(suff.size() - pref.size(), '#');
        }
        else
        {
            suff = string(pref.size() - suff.size(), '#') + suff;
        }
        TrieNode* p = root;
        string t = "";
        for (int i = 0; i < pref.size(); i++)
        {
            t = string({ pref[i],suff[suff.size() - i - 1] });
            if (p->next.count(t))
            {
                p = p->next[t];
            }
            else
            {
                return -1;
            }
        }
        return p->index;
    }
};

int main()
{
    vector<string> words = { "za" };
    WordFilter w(words);
    cout << w.f("za", "a") << endl;
}