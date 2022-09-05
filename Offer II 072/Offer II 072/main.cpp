#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        while (left < right)
        {
            int mid = (left + right) / 2 + 1;
            if (x / mid == mid)
            {
                return mid;
            }
            else if (x / mid < mid)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(15) << endl;
}