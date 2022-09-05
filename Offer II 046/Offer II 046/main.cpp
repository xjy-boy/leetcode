#include<iostream>
#include<queue>
#include<vector>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> queueList[2];
        TreeNode* p;
        int now = 0;
        queueList[now].push(root);
        while (true)
        {
            int index1 = now % 2;
            int index2 = (now + 1) % 2;
            result.push_back(queueList[index1].front()->val);
            while (!queueList[index1].empty())
            {
                p = queueList[index1].front();
                queueList[index1].pop();

                if (p->right != nullptr)
                {
                    queueList[index2].push(p->right);
                }

                if (p->left != nullptr)
                {
                    queueList[index2].push(p->left);
                }

            }
            if (queueList[index2].empty())
            {
                break;
            }
            now += 1;
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    TreeNode node1 = TreeNode(1);
    TreeNode node2 = TreeNode(2);
    TreeNode node3 = TreeNode(3);
    TreeNode node4 = TreeNode(4);
    TreeNode node5 = TreeNode(5);
    TreeNode node6 = TreeNode(6);
    TreeNode node7 = TreeNode(7);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node3.left = &node5;
    node3.right = &node6;
    node5.right = &node7;
    vector<int> result = solution.rightSideView(&node1);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}
