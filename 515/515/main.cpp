#include<iostream>
#include<vector>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root)
        {
            return ans;
        }
        queue<TreeNode*> searchQueue;
        searchQueue.emplace(root);
        while (!searchQueue.empty())
        {
            int size = searchQueue.size();
            int maxNum = INT_MIN;
            for (int i = 0; i < size; i++)
            {
                TreeNode* p = searchQueue.front();
                searchQueue.pop();
                if (p->val > maxNum)
                {
                    maxNum = p->val;
                }

                if (p->left)
                {
                    searchQueue.push(p->left);
                }
                if (p->right)
                {
                    searchQueue.push(p->right);
                }
            }
            ans.emplace_back(maxNum);
        }
        return ans;
    }
};