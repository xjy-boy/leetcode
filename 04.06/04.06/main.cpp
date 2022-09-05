#include<iostream>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
private:
    bool find = false;
    TreeNode *result = NULL;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
        {
            return NULL;
        }
        TreeNode* r = inorderSuccessor(root->left, p);
        
        if (r != NULL)
        {
            return r;
        }
        if (find)
        {
            return root;
        }
        else if (root == p)
        {
            find = true;
        }

        return inorderSuccessor(root->right, p);
    }
};