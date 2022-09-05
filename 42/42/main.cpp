#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //�����ݼ�ջ���ҵ�ÿ��Ԫ��֮���׸�������Ԫ��
        stack<int> smallStack;
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < height.size(); i++)
        {
            //��ջ��ͬʱ���Լ�����һ������
            while (!smallStack.empty()
                &&height[i] >= height[smallStack.top()])
            {
                //preΪ�ػ��߶�
                pre = smallStack.top();
                smallStack.pop();
                //��ջ���ջ��Ϊ���ߣ���ǰԪ��Ϊ�Ҳ�ǽ
                if (!smallStack.empty())
                {
                    ans += (i - smallStack.top() - 1)
                        * (min(height[i], height[smallStack.top()])
                            - height[pre]);
                }
            }
            smallStack.push(i);
        }
        return ans;
    }
};

int main()
{
    vector<int> input = { 4,2,0,3,2,5 };
    Solution s;
    cout << s.trap(input) << endl;
}