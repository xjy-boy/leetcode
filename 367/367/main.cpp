#include<iostream>

using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 2147483647)
        {
            return false;
        }
        int left = 1;
        int right = num;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int t = num / mid;
            if (mid == t)
            {
                return num % mid == 0;
            }
            else if (t < mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i < 17; i++)
    {
        cout << i << ":" << s.isPerfectSquare(i) << endl;
    }
}