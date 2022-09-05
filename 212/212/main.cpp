#include<iostream>
#include<vector>
#include<unordered_set>
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


class Solution {
private:
    unordered_set<string> ans;
    int m = 0;
    int n = 0;
public:
    void insert(TrieNode* root, string word)
    {
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
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        m = board.size();
        n = board[0].size();
        for (string word : words)
        {
            insert(root, word);
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans.size() == words.size())
                {
                    break;
                }
                search(board, i, j,"",root);
            }
            if (ans.size() == words.size())
            {
                break;
            }
        }
        
        vector<string> result;
        for (string word : ans)
        {
            result.emplace_back(word);
        }
        return result;
    }

    void search(vector<vector<char>>& board, int i, int j,string now,TrieNode *p)
    {
        char c = board[i][j];
        now += board[i][j];
        if (p->child[c - 'a'] == nullptr)
        {
            return;
        }
        else
        {
            p = p->child[c - 'a'];
            if (p->isWord)
            {
                ans.insert(now);
            }
        }
       
        board[i][j] = '.';
        if (i != 0 && board[i - 1][j] != '.')
        {
            search(board, i - 1, j, now, p);
        }

        if (i != m - 1 && board[i + 1][j] != '.')
        {
            search(board, i + 1, j, now, p);
        }

        if (j != 0 && board[i][j - 1] != '.')
        {
            search(board, i, j - 1, now, p);
        }

        if (j != n-1 && board[i][j + 1] != '.')
        {
            search(board, i, j + 1, now, p);
        }
        board[i][j] = c;
    }
};

int main()
{
    vector<vector<char>> board =
    {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = { "oath","pea","eat","rain" };
    Solution s;
    s.findWords(board, words);
}