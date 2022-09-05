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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q)
        {
            if (p->val == q->val && isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(!p && !q)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    TreeNode node11(1);
    TreeNode node12(2);
    TreeNode node13(3);

    TreeNode node21(1);
    TreeNode node22(2);
    TreeNode node23(3);

    node11.left = &node12;
    node11.right = &node13;

    node21.left = &node22;
    node21.right = &node23;

    Solution s;
    s.isSameTree(&node11, &node21);
}