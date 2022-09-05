#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k % 2 == 1)
        {
            return medianSlidingWindowOdd(nums, k);
        }
        else
        {
            return medianSlidingWindowEven(nums, k);
        }
    }

    //分两种情况,k为奇数和k为偶数
    //奇数
    vector<double> medianSlidingWindowOdd(vector<int>& nums, int k) {
        int mid = 0;
        priority_queue<int> left; //大根堆
        priority_queue<int,vector<int>,greater<int>> right; //小根堆
        //初始化
        for (int i = 0; i < k; i++)
        {
            left.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++)
        {
            right.push(left.top());
            left.pop();
        }
        mid = left.top();
        left.pop();
        vector<double> ans;
        ans.emplace_back(mid);
        unordered_map<int, int> counts;
        int pre = 0;

        for (int i = k; i < nums.size(); i++)
        {
            pre = nums[i - k];
            if (pre == nums[i])
            {
                ans.emplace_back(ans.back());
                continue;
            }
            //要删除的数不为mid，需要对mid进行处理
            if (pre != mid)
            {
                //要删除的数在left中
                if (pre < mid)
                {
                    //将mid加入left中，保持平衡
                    left.push(mid);
                }
                else
                {
                    //将mid加入right中，保持平衡
                    right.push(mid);
                }
                if (!counts.count(pre))
                {
                    counts[pre] = 1;
                }
                else
                {
                    counts[pre] += 1;
                }
            }
            //此时可以保证left和right的top不是要被删除的数
            if (nums[i] > left.top())
            {
                right.push(nums[i]);
                mid = right.top();
                right.pop();
                while (counts.count(right.top()))
                {
                    if (counts[right.top()] == 1)
                    {
                        counts.erase(right.top());
                    }
                    else
                    {
                        counts[right.top()] -= 1;
                    }
                    right.pop();
                }
            }
            else
            {
                left.push(nums[i]);
                mid = left.top();
                left.pop();
                while (counts.count(left.top()))
                {
                    if (counts[left.top()] == 1)
                    {
                        counts.erase(left.top());
                    }
                    else
                    {
                        counts[left.top()] -= 1;
                    }
                    left.pop();
                }
            }
            ans.emplace_back(mid);
        }
        return ans;
    }

    //分两种情况,k为奇数和k为偶数
    //偶数
    vector<double> medianSlidingWindowEven(vector<int>& nums, int k) {
        priority_queue<int> left; //大根堆
        priority_queue<int, vector<int>, greater<int>> right; //小根堆
        //初始化
        for (int i = 0; i < k; i++)
        {
            left.push(nums[i]);
        }
        for (int i = 0; i < k / 2; i++)
        {
            right.push(left.top());
            left.pop();
        }
        vector<double> ans;
        unordered_map<int, int> counts;
        int pre = 0;
        double leftNum = left.top();
        double rightNum = right.top();
        ans.emplace_back(leftNum + (rightNum - leftNum) / 2);

        for (int i = k; i < nums.size(); i++)
        {
            pre = nums[i - k];
            if (pre == nums[i])
            {
                ans.emplace_back(ans.back());
                continue;
            }
            //要删除的数为两侧的top
            if (left.top() == pre)
            {
                left.pop();
                //将right.top与nums[i]中的较小值加入left中，保持平衡
                right.push(nums[i]);
                left.push(right.top());
                right.pop();
            }
            else if (right.top() == pre)
            {
                right.pop();
                //将left.top与nums[i]中的较大值加入right中，保持平衡
                left.push(nums[i]);
                right.push(left.top());
                left.pop();
            }
            else
            {
                //要删除的数在left中
                if (pre < left.top())
                {
                    //将right.top与nums[i]中的较小值加入left中，保持平衡
                    right.push(nums[i]);
                    left.push(right.top());
                    right.pop();
                }
                else
                {
                    //将left.top与nums[i]中的较大值加入right中，保持平衡
                    left.push(nums[i]);
                    right.push(left.top());
                    left.pop();
                    //left.pop之后，left.top有可能为被删除的数
                }
                if (!counts.count(pre))
                {
                    counts[pre] = 1;
                }
                else
                {
                    counts[pre] += 1;
                }
            }
            //pop之后，top有可能为被删除的数
            while (counts.count(left.top()))
            {
                if (counts[left.top()] == 1)
                {
                    counts.erase(left.top());
                }
                else
                {
                    counts[left.top()] -= 1;
                }
                left.pop();
            }
            while (counts.count(right.top()))
            {
                if (counts[right.top()] == 1)
                {
                    counts.erase(right.top());
                }
                else
                {
                    counts[right.top()] -= 1;
                }
                right.pop();
            }
            leftNum = left.top();
            rightNum = right.top();
            ans.emplace_back(leftNum + (rightNum - leftNum) / 2);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,4,2,3 };
    s.medianSlidingWindow(nums, 4);
}