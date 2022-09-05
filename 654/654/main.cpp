#include<iostream>
#include<vector>
#include<stack>

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //递减单调栈
        //每个元素出栈后，栈顶元素为其父亲节点(右孩子)
        //每个元素要进入栈时，最后一个出栈的元素(其左侧最大的元素)是其左孩子(若有)
        //虚拟头节点，保证栈不为空，优化编码
        TreeNode ans(INT_MAX);
        stack<TreeNode*> searchStack;
        searchStack.push(&ans);
        TreeNode* p = nullptr;
        TreeNode* pre = nullptr;
        for (int& num : nums)
        {
            p = new TreeNode(num);
            pre = nullptr;
            while (p->val > searchStack.top()->val)
            {
                pre = searchStack.top();
                searchStack.pop();
                searchStack.top()->right = pre;
            }
            if (pre)
            {
                p->left = pre;
            }
            searchStack.push(p);
        }
        pre = searchStack.top();
        searchStack.pop();
        while (!searchStack.empty())
        {
            searchStack.top()->right = pre;
            pre = searchStack.top();
            searchStack.pop();
        }
        return ans.right;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,2,1,6,0,5 };
    s.constructMaximumBinaryTree(nums);
}