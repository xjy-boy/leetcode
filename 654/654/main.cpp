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
        //�ݼ�����ջ
        //ÿ��Ԫ�س�ջ��ջ��Ԫ��Ϊ�丸�׽ڵ�(�Һ���)
        //ÿ��Ԫ��Ҫ����ջʱ�����һ����ջ��Ԫ��(���������Ԫ��)��������(����)
        //����ͷ�ڵ㣬��֤ջ��Ϊ�գ��Ż�����
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