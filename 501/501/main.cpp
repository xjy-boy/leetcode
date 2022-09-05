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
    int pre = INT_MIN;
    int count = 0;
    int maxCount = 0;
public:
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        return ans;
    }

    void inOrder(TreeNode* root)
    {
        if (root)
        {
            inOrder(root->left);
            if (root->val == pre)
            {
                count += 1;
            }
            else
            {
                pre = root->val;
                count = 1;
            }
            if (count > maxCount)
            {
                ans.clear();
                ans.emplace_back(root->val);
                maxCount = count;
            }
            else if (count == maxCount)
            {
                ans.emplace_back(root->val);
            }
            inOrder(root->right);
        }
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    node1.right = &node2;
    Solution s;
    s.findMode(&node1);
}