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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        ans = 0;
        int res = search(root);
        return max(ans, res) - 1;
    }

    int search(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        int left = search(root->left);
        int right = right = search(root->right);;
        ans = max(ans, left + right + 1);
        return 1 + max(left, right);
    }
};