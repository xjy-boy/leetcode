#include<iostream>

using namespace std;

bool isBadVersion(int version)
{
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long int left = 1;
        long int right = n;
        while (left < right)
        {
            long int mid = (left + right) / 2;
            if (!isBadVersion(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};