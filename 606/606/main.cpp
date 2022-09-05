#include<iostream>
#include<string>

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
    string tree2str(TreeNode* root) {
        string ans = to_string(root->val);
        if (!root->left && !root->right)
        {
            return ans;
        }
        else if (!root->left)
        {
            ans = ans + "()" + "(" + tree2str(root->right) + ")";
            return ans;
        }
        else if (!root->right)
        {
            ans = ans  + "(" + tree2str(root->left) + ")";
            return ans;
        }
        else
        {
            ans = ans + "(" + tree2str(root->left) + ")"
                + "(" + tree2str(root->right) + ")";
            return ans;
        }
    }
};