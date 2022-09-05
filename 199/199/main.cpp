#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> searchQueue;
        searchQueue.push(root);
        while (!searchQueue.empty())
        {
            int val = -500;
            int size = searchQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* p = searchQueue.front();
                searchQueue.pop();
                if (p)
                {
                    val = p->val;
                    searchQueue.push(p->left);
                    searchQueue.push(p->right);
                }
            }
            if (val >= -100)
            {
                ans.push_back(val);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};