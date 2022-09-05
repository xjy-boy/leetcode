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
    int pre = 0;
    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        pre = -1e5 + 7;
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode* root) {
        if (root)
        {
            inOrder(root->left);
            int next = root->val - pre;
            if (next < ans)
            {
                ans = next;
            }
            pre = root->val;
            inOrder(root->right);
        }
    }
};
