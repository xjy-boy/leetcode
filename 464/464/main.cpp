#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> canWin; //1:������Ӯ��-1�������ԣ�0��δ����
    int target = 0;
    int maxInterger = 0;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
        {
            return true;
        }
        else if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
        {
            return false;
        }
        canWin = vector<int>(pow(2, maxChoosableInteger), 0);
        target = desiredTotal;
        maxInterger = maxChoosableInteger;
        return dfs(0) > 0;
    }

    int dfs(int symbol) {
        if (canWin[symbol] != 0)
        {
            return canWin[symbol];
        }
        int sum = 0;
        int now = 0; //��ǰѡ���ֵ��ˣ�ż��Ϊ���֣�
        int t = 1;
        for (int i = 1; i <= maxInterger; i++)
        {
            if (symbol & t)
            {
                sum += i;
                now += 1;
            }
            t = t << 1;
        }

        //�������Ϊ����ѡ������Ҫ���ֲ���ѡ�ĸ�����Ϊ��Ӯ״̬
        if (now % 2 == 1)
        {
            for (int i = maxInterger; i > 0; i--)
            {
                t = t >> 1;
                if (!(symbol & t))
                {
                    if ((sum + i) >= target)
                    {
                        canWin[symbol] = -1;
                        return canWin[symbol];
                    }
                    else
                    {
                        if (dfs(symbol | t) < 0)
                        {
                            canWin[symbol] = -1;
                            return canWin[symbol];
                        }
                    }
                }
            }
            canWin[symbol] = 1;
            return canWin[symbol];
        }
        //�������Ϊ�Լ�ѡ����ֻ��Ҫ�Լ���һ����Ϊ��Ӯ״̬����
        else
        {
            for (int i = maxInterger; i > 0; i--)
            {
                t = t >> 1;
                if (!(symbol & t))
                {
                    if ((sum + i) >= target)
                    {
                        canWin[symbol] = 1;
                        return canWin[symbol];
                    }
                    else
                    {
                        if (dfs(symbol | t) > 0)
                        {
                            canWin[symbol] = 1;
                            return canWin[symbol];
                        }
                    }
                }
            }
            canWin[symbol] = -1;
            return canWin[symbol];
        }
    }
};

int main()
{
    Solution s;
    s.canIWin(6, 16);
}