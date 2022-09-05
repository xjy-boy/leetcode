#include<iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
        {
            return false;
        }
        int t = sqrt(num);
        int ans = 1;
        int j = 0;
        for (int i = 2; i <= t; i++)
        {
            if (num % i == 0)
            {
                j = num / i;
                ans += i;
                if (i != j)
                {
                    ans += j;
                }
            }
        }
        return ans == num;
    }
};

int main()
{
    Solution s;
    s.checkPerfectNumber(28);
}