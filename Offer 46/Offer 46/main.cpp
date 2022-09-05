#include<iostream>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        int pre = 1;
        int ppre = 1;
        int preNum = 0;

        pre = 1;
        preNum = num % 10;
        num /= 10;
        while (num != 0)
        {
            int nowNum = num % 10;
            int now = 0;
            if (nowNum == 0 || nowNum * 10 + preNum > 25)
            {
                now = pre;
            }
            else
            {
                now = pre + ppre;
            }
            num /= 10;
            ppre = pre;
            pre = now;
            preNum = nowNum;
        }
        return pre;
    }
};

int main()
{
    Solution s;
    cout << s.translateNum(506) << endl;
}