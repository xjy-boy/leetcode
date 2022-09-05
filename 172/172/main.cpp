#include<iostream>

using namespace std;

class Solution {

public:
    /*
    int trailingZeroes(int n) {
        if (n < 10) 
        {
            if (n >= 5)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return (n / 10 ) * 2 + trailingZeroes(n / 10) + trailingZeroes(n % 10);
    }*/
    int trailingZeroes(int n) {
        if (n == 0)
        {
            return 0;
        }
        int length = log(n) / log(5);
        int ans = 0;
        int t = 5;
        for (int i = 1; i <= length; i++)
        {
            ans += n / t;
            t *= 5;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    int n = 120;
    cout << s.trailingZeroes(n) << endl;
}