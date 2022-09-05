#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n != 0)
        {
            if (n % 2 == 1)
            {
                ans += 1;
            }
            n /= 2;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(11) << endl;
}