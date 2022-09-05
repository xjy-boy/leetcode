#include<iostream>
#include<vector>
#include<queue>
#include<string>

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
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root);
        int n = pow(2, m) - 1;
        vector<vector<string>> ans = vector<vector<string>>(m, vector<string>(n, ""));
        TreeNode* p;
        queue<TreeNode*> searchQueue;
        queue<int> indexQueue;
        searchQueue.push(root);
        indexQueue.push((n - 1) / 2);
        int size = 0;
        int dif = pow(2, m - 1);
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            size = searchQueue.size();
            dif = dif / 2;
            for (int j = 0; j < size; j++)
            {
                p = searchQueue.front();
                index = indexQueue.front();
                searchQueue.pop();
                indexQueue.pop();
                ans[i][index] = to_string(p->val);

                if (p->left)
                {
                    searchQueue.push(p->left);
                    indexQueue.push(index - dif);
                }

                if (p->right)
                {
                    searchQueue.push(p->right);
                    indexQueue.push(index + dif);
                }
            }
        }
        return ans;
    }

    int getHeight(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            return max(getHeight(root->left), getHeight(root->right)) + 1;
        }
    }
};

int main()
{

}