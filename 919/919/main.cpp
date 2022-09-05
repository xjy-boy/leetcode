#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class CBTInserter {
private:
    TreeNode* r;
    vector<queue<TreeNode*>> nodeQueue;
    int index = 0;
public:
    CBTInserter(TreeNode* root) {
        r = root;
        nodeQueue = vector<queue<TreeNode*>>(2);
        nodeQueue[index].push(root);
        bool flag = true;
        TreeNode* p = nullptr;
        while (!nodeQueue[index].empty())
        {
            while (!nodeQueue[index].empty())
            {
                p = nodeQueue[index].front();
                if (p->left && p->right)
                {
                    nodeQueue[1 - index].push(p->left);
                    nodeQueue[1 - index].push(p->right);
                    nodeQueue[index].pop();
                }
                else
                {
                    if (p->left)
                    {
                        nodeQueue[1 - index].push(p->left);
                    }
                    return;
                }
            }
            index = 1 - index;
        }
    }

    int insert(int val) {
        TreeNode* p = nodeQueue[index].front();
        TreeNode* next = new TreeNode(val);
        if (p->left)
        {
            p->right = next;
            nodeQueue[1 - index].push(next);
            nodeQueue[index].pop();
            if (nodeQueue[index].empty())
            {
                index = 1 - index;
            }
        }
        else
        {
            p->left = next;
            nodeQueue[1 - index].push(next);
        }
        return p->val;
    }

    TreeNode* get_root() {
        return r;
    }
};
