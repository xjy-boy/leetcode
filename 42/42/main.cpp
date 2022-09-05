#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //单调递减栈，找到每个元素之后首个比其大的元素
        stack<int> smallStack;
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < height.size(); i++)
        {
            //出栈的同时可以计算下一个区域
            while (!smallStack.empty()
                &&height[i] >= height[smallStack.top()])
            {
                //pre为地基高度
                pre = smallStack.top();
                smallStack.pop();
                //出栈后的栈顶为左侧高，当前元素为右侧墙
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