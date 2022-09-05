#include<iostream>

int guess(int num)
{
	return -1;
}


class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int res = guess(mid);
            if (res == 0)
            {
                return mid;
            }
            else if (res > 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};