#include<iostream>
#include<vector>

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root)
        {
            return subRoot == nullptr;
        }
        else
        {
            if (checkTree(root, subRoot))
            {
                return true;
            }
            else
            {
                return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            }
        }
    }

    bool checkTree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root)
        {
            return subRoot == nullptr;
        }
        else if (!subRoot)
        {
            return false;
        }
        else
        {
            return root->val == subRoot->val &&
                checkTree(root->left, subRoot->left) &&
                checkTree(root->right, subRoot->right);
        }
    }
};