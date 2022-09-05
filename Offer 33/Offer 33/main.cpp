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
        //��������ջ
        stack<int> bigStack;
        //��ʼ����
        int root = INT_MAX;
        //�������
        for (int i = postorder.size() - 1; i >= 0; i--)
        {
            //���ӵ��������д��ڴ��ڸ��ڵ��ֵ������false
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