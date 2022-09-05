#include<iostream>

using namespace std;


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t = 0;
        for (int i = 0; i < 16; i++)
        {
            int left = 31 - i;
            bool rightFlag = n & (1 << i);
            bool leftFlag = n & (1 << left);
            if (rightFlag)
            {
                t = t | (1 << left);
            }
           
            if (leftFlag)
            {
                t = t | (1 << i);
            }
        }
        return t;
    }
};

int main()
{
    Solution s;

}