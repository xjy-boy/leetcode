#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        //设k为n的最小好进制，而s为n的k进制字符串
        //可知s为全1
        //s的长度越长，k越小
        //k的最大值（必定）为n-1,最小值（可能）为2
        //对于一个给定的s，可以通过二分查找找出是否有k满足
        //需要查找logn个s，对于每个s都需要logk=log(n-1)
        //最终时间复杂度为log^2n
        long nVal = stol(n);
        long mMax = floor(log(nVal) / log(2)) + 1;

        //m即为s的长度
        long t = 0;
        long left = 2;
        long right = nVal - 1;
        long mid = 0;
        unsigned long long sum = 0;
        //从大的开始
        for (int m = mMax; m > 2; m--)
        {
            //二分查找m对应的k
            left = 2;
            right = nVal - 1;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                sum = 0;
                if (pow(mid, m) > (double)LONG_MAX * (mid-1))
                {
                    right = mid - 1;
                    continue;
                }
                for (int i = 0; i < m; i++)
                {
                    sum = sum * mid + 1;
                }
                if (sum == nVal)
                {
                    return to_string(mid);
                }
                else if (sum > nVal)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }

        return to_string(nVal - 1);
    }
};



int main()
{
    Solution s;
    cout << s.smallestGoodBase("2251799813685247") << endl;
}