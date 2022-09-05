#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        int size = 0;
        TreeNode* p = nullptr;
        queue<TreeNode*> searchQueue;
        searchQueue.push(root);

        while (!searchQueue.empty())
        {
            size = searchQueue.size();
            ans = 0;
            for (int i = 0; i < size; i++)
            {
                p = searchQueue.front();
                searchQueue.pop();
                ans += p->val;
                if (p->left)
                {
                    searchQueue.push(p->left);
                }
                if (p->right)
                {
                    searchQueue.push(p->right);
                }
            }
        }
        return ans;
    }
};