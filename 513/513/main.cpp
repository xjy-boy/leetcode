#include<iostream>

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
private:
    int ans;
    int depth;
public:
    int findBottomLeftValue(TreeNode* root) {
        ans = 0;
        depth = 0;
        search(root, 1);
        return ans;
    }

    void search(TreeNode* root, int high)
    {
        if (!root)
        {
            return;
        }
        else
        {
            if (high > depth)
            {
                depth = high;
                ans = root->val;
            }
            search(root->left, high + 1);
            search(root->right, high + 1);
        }
    }
};