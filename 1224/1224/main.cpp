#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        int numLittle = 0; //出现次数小于当前最大出现次数的数字个数
        int maxCount = 0; //当前最大出现次数
        unordered_map<int, int> numCount;

        for (int i = 0; i < n; i++)
        {
            //统计各个数字出现次数
            if (!numCount[nums[i]])
            {
                numCount[nums[i]] = 1;
                if (maxCount > 0)
                {
                    numLittle += 1;
                }
            }
            else
            {
                numCount[nums[i]] += 1;
            }

            
            if (numCount[nums[i]] > maxCount)
            {
                numLittle = numCount.size() - 1;
                maxCount += 1;
            }
            else if (numCount[nums[i]] == maxCount)
            {
                numLittle -= 1;
            }

            //若当前所有数字出现次数相同
            if (numLittle == 0 && i != n-1)
            {
                ans = i + 2;
            }
            //若当前只有一个数字仅出现一次，其他数字相同
            else if (numLittle == 1 && 
                maxCount * (numCount.size()-1) == i)
            {
                ans = i + 1;
            }
            //若当前只有一个数字出现了maxCount次，其他数字出现maxCount-1次
            else if (numLittle == numCount.size() - 1
                && (maxCount-1) * numCount.size() == i)
            {
                ans = i + 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    cout << s.maxEqualFreq(nums) << endl;
}