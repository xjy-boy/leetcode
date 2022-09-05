#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> symbol;
    vector<int> now;
    int n = 0;

    inline int getIndex(vector<int>& needs)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (needs[i] < 0)
            {
                return -1;
            }
            res += symbol[i] * needs[i];
        }
        return res;
    }

    inline void setIndex(vector<int>& needs,int index)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            needs[i] = index / symbol[i];
            index = index % symbol[i];
        }
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = needs.size();
        symbol = vector<int>(n, 1);
        now = vector<int>(n, 0);

        int pre = 1;
        for (int i = 1; i < n; i++)
        {
            pre = pre * (needs[i - 1] + 1);
            symbol[i] = pre;
        }
        vector<int> dp = vector<int>(getIndex(needs) + 1, 0);

        //首先是不考虑使用礼包
        for (int i = 0; i < dp.size(); i++)
        {
            setIndex(now, i);
            for (int j = 0; j < n; j++)
            {
                dp[i] += price[j] * now[j];
            }
        }

        //考虑每个礼包
        int dif = 0;
        int p = 0;
        int index = 0;
        //进位
        int c = 0;
        int t = 0;
        bool canUse = true;
        for (vector<int> &s : special)
        {
            p = s[n];
            canUse = true;
            for (int i = 0; i < n; i++)
            {
                now[i] = s[i];
                if (s[i] > needs[i])
                {
                    canUse = false;
                    break;
                }
            }
            if (!canUse)
            {
                continue;
            }
            int index = getIndex(now);
            int dif = getIndex(now);
            while (index < dp.size())
            {
                dp[index] = min(dp[index], dp[index - dif] + p);
                c = 1;
                t = 0;
                while (t < n)
                {
                    now[t] += 1;
                    if (now[t] > needs[t])
                    {
                        now[t] = s[t];
                        t += 1;
                    }
                    else
                    {
                        break;
                    }
                }
                if (t >= n)
                {
                    break;
                }
                else
                {
                    index = getIndex(now);
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    Solution s;
    /*
    vector<int> p = { 2,3,4 };
    vector<int> n = { 1,2,1 };
    vector<vector<int>> sp = {
        {1,1,0,4},
        {2,2,1,9},
    };
    */

    /*
    vector<int> p = { 2,5 };
    vector<int> n = { 3,2 };
    vector<vector<int>> sp = {
        {3,0,5},
        {1,2,10},
    };*/

    vector<int> p = { 4,10,1,5,5,3 };
    vector<int> n = { 1,6,5,1,1,4 };
    vector<vector<int>> sp = {
        {1,2,3,3,4,1,8},
        {3,4,5,5,5,2,14},
        {2,4,5,1,1,3,22}
    };

    /*
    vector<int> p = { 4,3,2,9,8,8 };
    vector<int> n = { 6,5,5,6,4,1 };
    vector<vector<int>> sp = {
        {1,5,5,1,4,0,18},
        {3,3,6,6,4,2,32}
    };
    */
    cout << s.shoppingOffers(p, sp, n) << endl;
}