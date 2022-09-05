#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1)
        {
            return 0;
        }
        else if (buckets == 2)
        {
            return 1;
        }

        //dp[j][i]��ʾi������j��ʵ����Լ������������
        //�߽�㣺dp[0][i] = log(i),dp[i]
        //����dp[i][j]�ĵ�һ��ʵ�飬���Է�Ϊ���������
        //1.û������������ʱ���Լ��dp[i][j-1]��Ͱ
        //2.��һ������������ʱʣ������Լ��dp[i-1][j-1]��Ͱ�����ÿ�������Լ��dp[i-1][j-1]��Ͱ
        //3.����������������ʱʣ������Լ��dp[i-2][j-1]��Ͱ�����ÿ���������Լ���ʱʣ������Լ��dp[i-1][j-1]��Ͱ
        //...
        //i.��������������ʱû��ʣ��������������ȵ�Ͱֻ����һ����
        int t = minutesToTest / minutesToDie;
        vector<vector<int>> dp = vector<vector<int>>(t, vector<int>());
        //�߽�����,ֻ��һ��ʵ��
        int nextBuckets = 1;
        while (nextBuckets < buckets)
        {
            dp[0].emplace_back(nextBuckets);
            nextBuckets = nextBuckets << 1;
        }
        dp[0].emplace_back(nextBuckets);
        //
        int num = 1;
        int pig = 0;
        for (int i = 1; i < t; i++)
        {
            //0ͷ��ֻ�ܼ��һ��Ͱ
            dp[i].push_back(1);
            while (dp[i].back() < buckets)
            {
                nextBuckets = 0;
                num = 1;
                pig = dp[i].size();
                //����������0������
                for (int j = 0; j <= dp[i].size(); j++)
                {
                    if (j != 0)
                    {
                        num = num * (pig - j + 1) / j;
                    }
                    //numΪ�������dp[i-1][pig-j]Ϊʣ�µ���
                    nextBuckets += num * dp[i - 1][pig - j];
                }
                dp[i].emplace_back(nextBuckets);
            }
        }
        return dp[t - 1].size() - 1;
    }
};

int main()
{
    Solution s;
    cout << s.poorPigs(25, 15, 60) << endl;
}