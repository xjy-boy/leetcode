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
public:
    int countNodes(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        int high = getHigh(root);
        int left = pow(2, high - 1);
        int right = pow(2, high) - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (hasLeaf(root, mid, high))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (hasLeaf(root, left, high))
        {
            return left;
        }
        else
        {
            return left - 1;
        }
    }

    int getHigh(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            return getHigh(root->left) + 1;
        }
    }

    bool hasLeaf(TreeNode* root, int num,int high)
    {
        for (int i = high-2; i >= 0; i--)
        {
            if (num & (1 << i))
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return root != nullptr;
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    //node1.left = &node2;
    //node1.right = &node3;

    //node2.left = &node4;
    //node2.right = &node5;

    //node3.left = &node6;

    Solution s;
    cout << s.countNodes(nullptr);
}