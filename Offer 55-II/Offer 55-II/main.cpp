#include<iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balance(root).second;
    }

    pair<int, bool> balance(TreeNode* root) {
        if (!root)
        {
            return pair<int, bool>(0, true);
        }

        pair<int, bool> result1 = balance(root->left);
        pair<int, bool> result2 = balance(root->right);
        return pair<int, bool>(max(result1.first, result2.first) + 1, result1.second && result2.second && abs(result1.first - result2.first) < 2);
    }
};