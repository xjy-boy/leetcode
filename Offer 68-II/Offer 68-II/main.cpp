#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int high1 = 1;
        int high2 = 1;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> searchQueue;
        searchQueue.push(root);
        int high = 1;
        while (!searchQueue.empty())
        {
            int size = searchQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* now = searchQueue.front();
                searchQueue.pop();
                if (now == p)
                {
                    high1 = high;
                }
                if (now == q)
                {
                    high2 = high;
                }
                if (now->left)
                {
                    parent[now->left] = now;
                    searchQueue.push(now->left);
                }
                if (now->right)
                {
                    parent[now->right] = now;
                    searchQueue.push(now->right);
                }
            }
            high += 1;
        }
        while (high1 > high2)
        {
            p = parent[p];
            high1 -= 1;
        }
        while (high2 > high1)
        {
            q = parent[q];
            high2 -= 1;
        }
        while (p != q)
        {
            p = parent[p];
            q = parent[q];
        }
        return p;
    }
};