#include<iostream>


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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root)
        {
            TreeNode* p = new TreeNode(val);
            return p;
        }
        else if (val > root->val)
        {
            TreeNode* p = new TreeNode(val);
            p->left = root;
            return p;
        }
        else
        {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};