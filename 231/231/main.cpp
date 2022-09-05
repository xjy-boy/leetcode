#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
        {
            return false;
        }
        else
        {
            while (n > 1)
            {
                if (n % 2 != 0)
                {
                    return false;
                }
                else
                {
                    n = n / 2;
                }
            }
            return true;
        }
    }
};