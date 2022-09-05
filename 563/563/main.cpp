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
public:
    int ans = 0;
    int findTilt(TreeNode* root) {
        ans = 0;
        getSum(root);
        return ans;
    }

    int getSum(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        else
        {
            int sum1 = getSum(root->left);
            int sum2 = getSum(root->right);
            ans += abs(sum1 - sum2);
            return sum1 + sum2 + root->val;
        }
    }
};