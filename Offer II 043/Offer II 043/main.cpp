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

class CBTInserter {
private:
    TreeNode * treeRoot;
    queue<TreeNode*> nodeQueue;
public:
    CBTInserter(TreeNode* root) {
        treeRoot = root;
        //层级遍历,依次找出需要添加子孙节点的节点
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        TreeNode* p;
        while (!bfsQueue.empty())
        {
            p = bfsQueue.front();
            bfsQueue.pop();
            if (p->left == nullptr && p->right == nullptr)
            {
                nodeQueue.push(p);
            }
            else if (p->right == nullptr)
            {
                bfsQueue.push(p->left);
                nodeQueue.push(p);
            }
            else
            {
                bfsQueue.push(p->left);
                bfsQueue.push(p->right);
            }
        }
    }

    int insert(int v) {
        TreeNode* p = nodeQueue.front();
        if (p->left == nullptr)
        {
            p->left = new TreeNode(v, nullptr, nullptr);
            nodeQueue.push(p->left);
            return p->val;
        }
        else
        {
            nodeQueue.pop();
            p->right = new TreeNode(v, nullptr, nullptr);
            nodeQueue.push(p->right);
            return p->val;
        }
    }

    TreeNode* get_root() {
        return treeRoot;
    }
};

int main()
{
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(1);
    node1.left = &node2;
    
    CBTInserter c = CBTInserter(&node1);
    
    cout << c.insert(3) << endl;
    c.get_root();
    cout << c.insert(4) << endl;
    c.get_root();
}