#include<iostream>
#include<vector>
#include<string>

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
private:
    vector<int> now;
    vector<string> ans;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        now.clear();
        ans.clear();
        search(root, "");
        return ans;
    }

    void search(TreeNode* root,string path)
    {
        if (root)
        {
            path += to_string(root->val);
            if (!root->left && !root->right)
            {
                ans.emplace_back(path);
            }
            else
            {
                path += "->";
                search(root->left, path);
                search(root->right, path);
            }
        }
    }
};
