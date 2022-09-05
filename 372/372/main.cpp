#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        a = a % 1337;
        vector<int> dp = vector<int>(b.size(), 0);
        for (int i = b.size() - 1; i >= 0; i--)
        {
            int next = 1;
            for (int j = 0; j < 10; j++)
            {
                if (j == b[i])
                {
                    dp[i] = next;
                }
                next = (next * a) % 1337;
            }
            a = next;
        }
        int ans = 1;
        for (int num : dp)
        {
            ans = (ans * num) % 1337;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = { 2,0,0 };
    int a = 2147483647;
    Solution s;
    cout << s.superPow(a, nums) << endl;
}