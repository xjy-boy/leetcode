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
    int sumOfLeftLeaves(TreeNode* root) {
        return search(root, false);
    }

    int search(TreeNode* root, bool isLeft) {
        if (!root)
        {
            return 0;
        }
        else
        {
            if (isLeft && !root->left && !root->right)
            {
                return root->val;
            }
            else
            {
                int ans = 0;
                ans += search(root->left, true);
                ans += search(root->right, false);
                return ans;
            }
        }
    }
};