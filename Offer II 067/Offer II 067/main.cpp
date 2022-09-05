#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TrieNode
{
    TrieNode* left;
    TrieNode* right;
    int val;
    TrieNode(int _val)
    {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;

        TrieNode* root = new TrieNode(0);
        TrieNode* p = root;
        for (int num : nums)
        {
            p = root;
            for (int i = 30; i >= 0; i--)
            {
                if (num & (1 << i))
                {
                    if (!p->right)
                    {
                        p->right = new TrieNode((1 << i));
                    }
                    p = p->right;
                }
                else
                {
                    if (!p->left)
                    {
                        p->left = new TrieNode((1 << i));
                    }
                    p = p->left;
                }
            }
        }
        p = root;
        queue<pair<TrieNode*, TrieNode*>> searchQueue;
        int i = 30;
        for (i = 30; i >= 0; i--)
        {
            if (p->left && p->right)
            {
                searchQueue.push(pair<TrieNode*, TrieNode*>(p->left, p->right));
                break;
            }
            else if (p->right)
            {
                result = result | (1 << i);
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        if (i < 0)
        {
            return result;
        }
        result = result | (1 << i);
        i -= 1;
        while (!searchQueue.empty())
        {
            int size = searchQueue.size();
            int needPop = 0;
            bool flag1 = false;
            for (int j = 0; j < size; j++)
            {
                pair<TrieNode*, TrieNode*> nodePair = searchQueue.front();
                searchQueue.pop();
                // ©иртн╙1
                if (nodePair.first->left && nodePair.second->right)
                {
                    flag1 = true;
                    searchQueue.push(pair<TrieNode*, TrieNode*>(nodePair.first->left, nodePair.second->right));
                }
                if (nodePair.first->right && nodePair.second->left)
                {
                    flag1 = true;
                    searchQueue.push(pair<TrieNode*, TrieNode*>(nodePair.first->right, nodePair.second->left));
                }

                if (!flag1)
                {
                    if (nodePair.first->left && nodePair.second->left)
                    {
                        needPop += 1;
                        searchQueue.push(pair<TrieNode*, TrieNode*>(nodePair.first->left, nodePair.second->left));
                    }
                    if (nodePair.first->right && nodePair.second->right)
                    {
                        needPop += 1;
                        searchQueue.push(pair<TrieNode*, TrieNode*>(nodePair.first->right, nodePair.second->right));
                    }
                }
            }
            if (flag1)
            {
                result = result | (1 << i);
                for (int j = 0; j < needPop; j++)
                {
                    searchQueue.pop();
                }
            }
            i -= 1;
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1 };
    Solution s;
    cout << s.findMaximumXOR(nums) << endl;
}