#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[31] = {0};
        for (int num : nums)
        {
            for (int i = 0; i < 31; i++)
            {
                if (num & (1 << i))
                {
                    count[i] += 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            if (count[i] % 3 != 0)
            {
                ans += 1 << i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> num = { 3,2147483647,3,3 };
    cout << s.singleNumber(num) << endl;
}