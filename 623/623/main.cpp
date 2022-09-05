#include<iostream>
#include<queue>

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
        {
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }
        else
        {
            depth -= 1;
            queue<TreeNode*>searchQueue;
            searchQueue.push(root);
            size_t t = 0;
            TreeNode* p;
            TreeNode* p1;
            TreeNode* p2;
            for (int i = 1; i < depth; i++)
            {
                t = searchQueue.size();
                for (int j = 0; j < t; j++)
                {
                    p = searchQueue.front();
                    searchQueue.pop();
                    if (p->left)
                    {
                        searchQueue.push(p->left);
                    }
                    if (p->right)
                    {
                        searchQueue.push(p->right);
                    }
                }
            }

            while (!searchQueue.empty())
            {
                p = searchQueue.front();
                searchQueue.pop();
                p1 = new TreeNode(val);
                p2 = new TreeNode(val);
                p1->left = p->left;
                p2->right = p->right;
                p->left = p1;
                p->right = p2;
            }
            return root;
        }
    }
};