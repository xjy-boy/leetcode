#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        for (int &num : nums)
        {
            sum += num;
            if (sum < ans)
            {
                ans = sum;
            }
        }
        return 1 - ans;
    }

    int minStartValue1(vector<int>& nums) {
        int min = 0, sum = 0;
        for (auto& n : nums) {
            sum += n;
            if (sum < min) min = sum;
        }
        return 1 - min;
    }
};