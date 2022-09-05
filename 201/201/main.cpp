#include<iostream>


using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        int length = right - left;
        for (int i = 0; i < 32; i++)
        {
            int now = (1 << i);
            if (now > left)
            {
                break;
            }
            else if (length >= now)
            {
                continue;
            }
            else
            {
                if ((left & now) && (right & now))
                {
                    ans = ans | now;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(0, 0) << endl;
}