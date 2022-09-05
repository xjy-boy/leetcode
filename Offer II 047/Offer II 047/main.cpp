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
public:
    TreeNode* pruneTree(TreeNode* root) {
        postOrder(root);
        return root;
    }

    int postOrder(TreeNode* &root)
    {
        int c1 = 0;
        int c2 = 0;
        if (root->left != nullptr)
        {
            c1 = postOrder(root->left);
        }
        if (root->right != nullptr)
        {
            c2 = postOrder(root->right);
        }
        
        if (root->val == 0 && c1 == 0 && c2 == 0)
        {
            root = nullptr;
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    Solution solution = Solution();
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(1);
    TreeNode node3 = TreeNode(0);
    TreeNode node4 = TreeNode(1);
    TreeNode node5 = TreeNode(1);
    TreeNode node6 = TreeNode(0);
    TreeNode node7 = TreeNode(0);
    TreeNode node8 = TreeNode(0);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.right = &node8;
    solution.pruneTree(&node1);
}
