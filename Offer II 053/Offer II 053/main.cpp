#include<iostream>
#include<queue>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
        {
            return root;
        }
        // 当前根节点值比p小时，p的后继一定在root的右子树
        if (root->val < p->val)
        {
            return inorderSuccessor(root->right, p);
        }
        // 当前根节点值比p大时，p的后继一定在root的左子树，或为
        else if (root->val > p->val)
        {
            TreeNode* result = inorderSuccessor(root->left, p);
            if (result == nullptr)
            {
                return root;
            }
            else
            {
                return result;
            }
        }
        // 当前根节点为p节点时
        else
        {
            if (root->right)
            {
                return inorderSuccessor(root->right, p);
            }
            else
            {
                return inorderSuccessor(root->left, p);
            }
        }
    }
};

int main()
{
    Solution solution;
    TreeNode node0 = TreeNode(0);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);
    TreeNode node4 = TreeNode(4);
    TreeNode node5 = TreeNode(5);
    TreeNode node6 = TreeNode(6);
    TreeNode node7 = TreeNode(7);
    TreeNode node8 = TreeNode(8);
    TreeNode node9 = TreeNode(9);
    node6.left = &node2;
    node6.right = &node8;
    node2.left = &node0;
    node2.right = &node4;
    node8.left = &node7;
    node8.right = &node9;
    node4.left = &node3;
    node4.right = &node5;

    TreeNode *p = solution.inorderSuccessor(&node6, &node2);
    cout << endl;
}

