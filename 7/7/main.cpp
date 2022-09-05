#include<iostream>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        if (x > 0)
        {
            return reversePositive(x);
        }
        else
        {
            return reverseNegative(x);
        }
    }

    int reversePositive(int x)
    {
        int ans = 0;
        while (x != 0)
        {
            int t = x % 10;
            if (ans > (INT_MAX - t )/ 10)
            {
                return 0;
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

    int reverseNegative(int x)
    {
        int ans = 0;
        while (x != 0)
        {
            int t = x % 10;
            if (ans < (INT_MIN - t) / 10)
            {
                return 0;
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(INT_MIN) << endl;
}