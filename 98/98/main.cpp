#include<iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
private:
    bool flag = true;
    int pre = INT_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }
        if (!isValidBST(root->left))
        {
            return false;
        }
        if (flag)
        {
            pre = root->val;
            flag = false;
        }
        else if (root->val <= pre)
        {
            return false;
        }
        pre = root->val;
        if (!isValidBST(root->right))
        {
            return false;
        }
        return true;
    }
};