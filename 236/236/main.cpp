#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     TreeNode(TreeNode *t) : val(t->val), left(t->left), right(t->right) {}
};

class Solution {
private:
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    bool flag = false;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        flag = false;
        find(root, p, path1);
        flag = false;
        find(root, q, path2);

        int index = min(path1.size(), path2.size()) - 1;
        for (int i = index; i >= 0; i--)
        {
            if (path1[i] == path2[i])
            {
                return path1[i];
            }
        }
        return root;
    }

    void find(TreeNode* root, TreeNode* p, vector<TreeNode*>& path)
    {
        if (!root || flag)
        {
            return;
        }
        path.emplace_back(root);
        if (root == p)
        {
            flag = true;
            return;
        }

        find(root->left, p, path);
        find(root->right, p, path);
        if (!flag)
        {
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);

    node3.left = &node5;
    node3.right = &node1;

    node1.left = &node0;
    node1.right = &node8;

    node5.left = &node6;
    node5.right = &node2;

    node2.left = &node7;
    node2.right = &node4;

    s.lowestCommonAncestor(&node3, &node5, &node1);
}