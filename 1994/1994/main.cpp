#include<iostream>
#include<vector>
#include<array>

using namespace std;

class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int result = 0;
        int mod = 1000000007;
        int mask[31] =
        {
            0,
            0,1,2,-1,4,
            3,8,-1,-1,5,
            16,-1,32,9,6,
            -1,64,-1,128,-1,
            10,17,256,-1,-1,
            33,-1,-1,512,7,
        };
        int presum[31] = { 
            0,
            0,1,3,7,7,
            7,15,15,15,15,
            31,31,63,63,63,
            63,127,127,255,255,
            255,255,511,511,511,
            511,511,511,1023,1023,
        };
        int freq[31] = { 0 };
        int f[1024] = { 0 };
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]] += 1;
        }
        f[0] = 1;
        for (int i = 0; i < freq[1]; i++)
        {
            f[0] = ( f[0] * 2 ) % mod;
        }

        for (int i = 2; i < 31; i++)
        {
            if (mask[i] < 0 || freq[i] == 0)
            {
                continue;
            }

            for (int j = presum[i]; j > 0; j--)
            {
                if ((j & mask[i]) == mask[i])
                {
                    f[j] = (f[j] +(long long) f[j ^ mask[i]] * freq[i]) % mod;
                }
            }

        }

        for (int i = 1; i < 1024; i++)
        {
            result = (result + f[i]) % mod;
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> nums = { 1,2,2,3 };
    cout << solution.numberOfGoodSubsets(nums) << endl;
}