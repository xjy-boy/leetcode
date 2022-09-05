#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        int left = 1;
        int sum = 0;
        for (int i = 1; i <= (target + 1) / 2; i++)
        {
            sum += i;
            while (sum > target)
            {
                sum -= left;
                left += 1;
            }
            if (sum == target)
            {
                ans.emplace_back(vector<int>());
                for (int j = left; j <= i; j++)
                {
                    ans.back().emplace_back(j);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.findContinuousSequence(1);
}