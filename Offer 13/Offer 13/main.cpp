#include<iostream>
#include<vector>
using namespace std;



class Solution {
private:
    vector<int> sum;
    int getSum(int x)
    {
        if (x >= sum.size())
        {
            for (int i = sum.size(); i <= x; i++)
            {
                int result = 0;
                int t = i;
                while (t != 0)
                {
                    result += t % 10;
                    t /= 10;
                }
                sum.emplace_back(result);
            }
        }
        return sum[x];
    }
public:
    int movingCount(int m, int n, int k) {
        
        vector<vector<bool>> reachable;
        reachable.emplace_back(vector<bool>(n, false));
        int ans = 0;
        int actualM = m;
        int actualN = n;
        for (int i = 0; i < n; i++)
        {
            if (getSum(i) > k)
            {
                actualM = min(m, i);
                actualN = i;
                break;
            }
            reachable[0][i] = true;
            ans += 1;
        }

        for (int i = 1; i < actualM; i++)
        {
            reachable.emplace_back(vector<bool>(n, false));
            if (reachable[i - 1][0] && getSum(i) <= k)
            {
                reachable[i][0] = true;
                ans += 1;
            }
            for (int j = 1; j < actualN; j++)
            {
                if (getSum(i) + getSum(j) <= k)
                {
                    reachable[i][j] = reachable[i - 1][j] || reachable[i][j - 1];
                    if (reachable[i][j])
                    {
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.movingCount(3, 1, 0) << endl;

}