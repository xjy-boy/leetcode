#include<iostream>


using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:

    pair<int,int> seach(TreeNode* root)
    {
        if (!root)
        {
            return {0,0};
        }
        pair<int, int> left = seach(root->left);
        pair<int, int> right = seach(root->right);

        //打劫当前节点
        int ans1 = root->val + left.second + right.second;

        //不打劫当前节点
        int ans2 = max(left.first, left.second) + max(right.first, right.second);

        return { ans1,ans2 };
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = seach(root);
        return max(ans.first, ans.second);
    }
};