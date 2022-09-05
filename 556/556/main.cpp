#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int nextGreaterElement(int n1) {
        long num = n1;
        long t = 1;
        long now = 0;
        long pre = 0;
        if (num < 10)
        {
            return -1;
        }
        now = num % 10;
        vector<int> nums = vector<int>(10, 0);
        nums[now] += 1;
        pre = now;
        while (num / 10 >= t)
        {
            t = t * 10;
            now = (num / t) % 10;

            //可以进行调换
            if (now < pre)
            {
                nums[now] += 1;
                num -= now * t + num % t;
                //找到大于now的最小数
                for (int i = now + 1; i < 10; i++)
                {
                    if (nums[i] > 0)
                    {
                        pre = i;
                        nums[i] -= 1;
                        break;
                    }
                }
                num += pre * t;
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < nums[i]; j++)
                    {
                        t = t / 10;
                        num += i * t;
                    }
                }
                if (num > INT_MAX)
                {
                    return -1;
                }
                else
                {
                    return num;
                }
            }
            else
            {
                nums[now] += 1;
                pre = now;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    //cout << 2147483647 << endl;
    cout << s.nextGreaterElement(1999999999) << endl;
}