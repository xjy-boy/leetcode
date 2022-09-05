#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        //��kΪn����С�ý��ƣ���sΪn��k�����ַ���
        //��֪sΪȫ1
        //s�ĳ���Խ����kԽС
        //k�����ֵ���ض���Ϊn-1,��Сֵ�����ܣ�Ϊ2
        //����һ��������s������ͨ�����ֲ����ҳ��Ƿ���k����
        //��Ҫ����logn��s������ÿ��s����Ҫlogk=log(n-1)
        //����ʱ�临�Ӷ�Ϊlog^2n
        long nVal = stol(n);
        long mMax = floor(log(nVal) / log(2)) + 1;

        //m��Ϊs�ĳ���
        long t = 0;
        long left = 2;
        long right = nVal - 1;
        long mid = 0;
        unsigned long long sum = 0;
        //�Ӵ�Ŀ�ʼ
        for (int m = mMax; m > 2; m--)
        {
            //���ֲ���m��Ӧ��k
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