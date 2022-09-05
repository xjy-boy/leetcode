#include<iostream>
#include<vector>
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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int index = 1;
        if (!root)
        {
            return {};
        }
        deque<TreeNode*> searchQueue;

        vector<vector<int>> ans;
        searchQueue.push_back(root);
        while (!searchQueue.empty())
        {
            int size = searchQueue.size();
            vector<int> result;
            //Ë«Êý²ã
            if (index % 2 == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    if (searchQueue.back()->right) {
                        searchQueue.push_front(searchQueue.back()->right);
                    }
                    if (searchQueue.back()->left) {
                        searchQueue.push_front(searchQueue.back()->left);
                    }
                    result.push_back(searchQueue.back()->val);
                    searchQueue.pop_back();
                }
            }
            //µ¥Êý²ã
            else
            {
                for (int i = 0; i < size; i++)
                {
                    if (searchQueue.front()->left) {
                        searchQueue.push_back(searchQueue.front()->left);
                    }
                    if (searchQueue.front()->right) {
                        searchQueue.push_back(searchQueue.front()->right);
                    }
                    result.push_back(searchQueue.front()->val);
                    searchQueue.pop_front();
                }
            }
            ans.emplace_back(result);
            index += 1;
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
    s.zigzagLevelOrder(&node1);
}