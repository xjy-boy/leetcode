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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.emplace_back(root, 1L);
        while (!arr.empty()) {
            vector<pair<TreeNode*, unsigned long long>> tmp;
            for (auto& p : arr) {
                if (p.first->left) {
                    tmp.emplace_back(p.first->left, p.second * 2);
                }
                if (p.first->right) {
                    tmp.emplace_back(p.first->right, p.second * 2 + 1);
                }
            }
            res = max(res, arr.back().second - arr[0].second + 1);
            arr = move(tmp);
        }
        return res;
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
    TreeNode node7(7);
    TreeNode node8(8);
    node1.left = &node2;
    node1.right = &node3;

    node2.left = &node4;
    node3.left = &node5;

    node4.left = &node6;
    node5.left = &node7;

    node6.left = &node8;
    
    Solution s;
    cout << s.widthOfBinaryTree(&node1) << endl;
}