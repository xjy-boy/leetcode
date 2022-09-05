#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct MyData {
    int data, index;
    MyData(int _data,int _index)
    {
        data = _data;
        index = _index;
    }

    bool operator<(MyData a) const {
        return data < a.data;
    }

    bool operator>(MyData a) const {
        return data > a.data;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
        {
            return {};
        }
        deque<int> biggerQueue;
        int t = k - 1;
        vector<int> ans = vector<int>(nums.size() - t, 0);
        for (int i = 0; i < t; i++)
        {
            while (!biggerQueue.empty() && nums[i] >= nums[biggerQueue.back()])
            {
                biggerQueue.pop_back();
            }
            biggerQueue.push_back(i);
        }
        for (int i = t; i < nums.size(); i++)
        {
            while (!biggerQueue.empty() && nums[i] >= nums[biggerQueue.back()])
            {
                biggerQueue.pop_back();
            }
            biggerQueue.push_back(i);
            while (biggerQueue.front() < i - t)
            {
                biggerQueue.pop_front();
            }
            ans[i - t] = nums[biggerQueue.front()];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,-1 };
    s.maxSlidingWindow(nums, 1);
}