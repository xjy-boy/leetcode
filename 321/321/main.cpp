#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> stacks;
    int targetK = 0;
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int length1 = nums1.size();
        int length2 = nums2.size();

        //遍历nums1的每种取数个数的可能
        int start = max(0, k - length2);
        int end = min(k, length1);
        stacks = vector<vector<int>>(2);
        vector<int> ans = vector<int>(k);
        targetK = k;
        int index1 = 0;
        int index2 = 0;
        int t1 = 0;
        int t2 = 0;
        int next = 0;
        bool isBig = false;

        for (int i = start; i <= end; i++)
        {
            //从num1选出长度为i的最大子序列，
            updateLongestStack(0, i, nums1);
            //从num2选出长度为k-i的最大子序列
            updateLongestStack(1, k - i, nums2);

            index1 = 0;
            index2 = 0;
            isBig = false;
            //尝试合并
            for (int j = 0; j < k; j++)
            {
                if (index1 == stacks[0].size())
                {
                    next = stacks[1][index2];
                    index2 += 1;
                }
                else if (index2 == stacks[1].size())
                {
                    next = stacks[0][index1];
                    index1 += 1;
                }
                else
                {
                    if (stacks[0][index1] > stacks[1][index2])
                    {
                        next = stacks[0][index1];
                        index1 += 1;
                    }
                    else if(stacks[0][index1] < stacks[1][index2])
                    {
                        next = stacks[1][index2];
                        index2 += 1;
                    }
                    else
                    {
                        //两个数值相等，要比较后面的数
                        t1 = index1;
                        t2 = index2;
                        next = -1;
                        while (t1 < stacks[0].size() && t2 < stacks[1].size())
                        {
                            if (stacks[0][t1] > stacks[1][t2])
                            {
                                next = stacks[0][index1];
                                index1 += 1;
                                break;
                            }
                            else if (stacks[0][t1] < stacks[1][t2])
                            {
                                next = stacks[1][index2];
                                index2 += 1;
                                break;
                            }
                            t1 += 1;
                            t2 += 1;
                        }
                        //后面的完全相等
                        if (next == -1)
                        {
                            //优先选择长的
                            if (t1 == stacks[0].size())
                            {
                                next = stacks[1][index2];
                                index2 += 1;
                            }
                            else
                            {
                                next = stacks[0][index1];
                                index1 += 1;
                            }
                        }
                    }
                }

                if (!isBig)
                {
                    if (next < ans[j])
                    {
                        break;
                    }
                    else if (next > ans[j])
                    {
                        isBig = true;
                    }
                }
                ans[j] = next;
            }
        }
        return ans;
    }

    void updateLongestStack(int index, int length, vector<int>& nums) {
        stacks[index].clear();
        int remain = nums.size() - length;
        for (int& num : nums)
        {
            //出栈相当于删去数字
            while (remain > 0 && !stacks[index].empty()
                && num > stacks[index].back())
            {
                stacks[index].pop_back();
                remain -= 1;
            }

            if (stacks[index].size() < length)
            {
                stacks[index].emplace_back(num);
            }
            //栈满后删去数字
            else
            {
                remain -= 1;
            }
        }
    }
};


int main()
{
    Solution s;
    vector<int>nums1 = { 2,5,6,4,4,0 };
    vector<int>nums2 = { 7,3,8,0,6,5,7,6,2 };
    s.maxNumber(nums1, nums2, 15);
}