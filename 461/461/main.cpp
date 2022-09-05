#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int t = 1;
        for (int i = 0; i < 32; i++)
        {
            if ((x & t) ^ (y & t))
            {
                ans += 1;
            }
            if (i != 31)
            {
                t = t << 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.hammingDistance(1, 3) << endl;
}