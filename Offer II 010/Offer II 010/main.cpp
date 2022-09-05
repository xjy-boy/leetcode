#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> presumNum;
        int presum = 0;
        int result = 0;
        presumNum[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            presum += nums[i];
            if (presumNum.count(presum - k))
            {
                result += presumNum[presum - k];
            }
            if (!presumNum.count(presum))
            {
                presumNum[presum] = 1;
            }
            else
            {
                presumNum[presum] += 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    int k = 0;
    vector<int> nums = { 1 };
    cout << solution.subarraySum(nums, k) << endl;
}