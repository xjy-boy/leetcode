#include<iostream>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
        {
            return nullptr;
        }
        else
        {
            if (root->val != key)
            {
                root->left = deleteNode(root->left, key);
                root->right = deleteNode(root->right, key);
            }
            else
            {
                root = deleteNode(root);
            }
            return root;
        }
    }

    //找出右子树中最小的节点和其父节点
    TreeNode* deleteNode(TreeNode* root) {
        TreeNode* p = root->right;
        TreeNode* pre = root;
        if (!p)
        {
            return root->left;
        }

        while (p->left)
        {
            pre = p;
            p = p->left;
        }
        if (pre == root)
        {
            root->val = p->val;
            root->right = p->right;
        }
        else
        {
            root->val = p->val;
            pre->left = p->right;
        }
        return root;
    }
};