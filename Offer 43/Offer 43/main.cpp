#include<iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        int k = 0;
        int t = n;
        while (t != 0)
        {
            k += 1;
            t /= 10;
        }
        
        int ten = pow(10, k - 1);
        int pre = 0;
        t = n;
        for (int i = 0; i < k; i++)
        {
            //当前位上的数字
            int nowNum = t / ten;
            t -= nowNum * ten;
            //为0
            if (nowNum == 0)
            {
                ans += pre * ten;
            }
            else if (nowNum == 1)
            {
                ans += pre * ten + t + 1;
            }
            else
            {
                ans += (pre + 1) * ten;
            }
            pre = pre * 10 + nowNum;
            ten /= 10;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    for (int i = 0; i <= 100; i++)
    {
        cout << i << "\t" <<s.countDigitOne(i) << endl;
    }
}