#include<iostream>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        return max(maxDepth(root->right), maxDepth(root->left)) + 1;
    }
};

