#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> searchQueue;
        vector<vector<int>> ans;
        searchQueue.push(root);
        int level = 0;
        while (!searchQueue.empty())
        {
            vector<int> result;
            int length = searchQueue.size();
            level += 1;
            for (int i = 0; i < length; i++)
            {
                TreeNode* p = searchQueue.front();
                searchQueue.pop();
                if (p)
                {
                    result.emplace_back(p->val);
                    searchQueue.push(p->left);
                    searchQueue.push(p->right);
                }
            }
            if (!result.empty())
            {
                if (level % 2 == 0)
                {
                    reverse(result.begin(), result.end());
                }
                ans.emplace_back(result);
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode node1(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    TreeNode node5(7);
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    Solution s;
    s.levelOrder(&node1);
}