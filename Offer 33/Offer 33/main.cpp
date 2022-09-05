#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty())
        {
            return true;
        }
        //单调递增栈
        stack<int> bigStack;
        //初始条件
        int root = INT_MAX;
        //倒序遍历
        for (int i = postorder.size() - 1; i >= 0; i--)
        {
            //左孩子的右子树中存在大于父节点的值，返回false
            if (postorder[i] > root)
            {
                return false;
            }
            while (!bigStack.empty() && bigStack.top() > postorder[i])
            {
                root = bigStack.top();
                bigStack.pop();
            }
            bigStack.push(postorder[i]);
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> num = { 1,3,2,6,5 };
    cout << s.verifyPostorder(num) << endl;
}