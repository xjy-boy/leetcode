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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> searchQueue;
        vector<double> ans;
        searchQueue.push(root);
        int size = 0;
        double sum = 0;
        TreeNode* p;
        while (!searchQueue.empty())
        {
            size = searchQueue.size();
            sum = 0;
            for (int i = 0; i < size; i++)
            {
                p = searchQueue.front();
                searchQueue.pop();
                sum += (double)p->val;
                if (p->left)
                {
                    searchQueue.push(p->left);
                }
                if (p->right)
                {
                    searchQueue.push(p->right);
                }
            }
            ans.emplace_back(sum / size);
        }
        return ans;
    }
};