#include<iostream>

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
    int pre = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        pre = k;
        return kthSmallest(root);
    }

    int kthSmallest(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int left = kthSmallest(root->left);
        pre -= 1;
        if (pre == 0)
        {
            return root->val;
        }
        else if (pre < 0)
        {
            return left;
        }
        else
        {
            return kthSmallest(root->right);
        }
    }
};

int main()
{
    Solution s;
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);

    node5.left = &node3;
    node5.right = &node6;

    node3.left = &node2;
    node3.right = &node4;

    node2.left = &node1;

    for (int i = 1; i <= 6; i++)
    {
        cout << s.kthSmallest(&node5, i) << endl;
    }
}