#include<iostream>
#include<vector>

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
private:
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root)
    {
        if (!root)
        {
            return;
        }
        else
        {
            inorder(root->left);
            ans.emplace_back(root->val);
            inorder(root->right);
        }
    }
};