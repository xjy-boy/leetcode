#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<vector<int>> s;
        int m = matrix.size();
        int n = matrix[0].size();
        s.emplace_back(n, 0);
        for (int i = 0; i < m; i++)
        {
            s.emplace_back(n, 0);
        }

        int ans = INT_MIN;
        
        //计算每列的前缀和
        int pre = 0;
        for (int i = 0; i < n; i++)
        {
            pre = 0;
            for (int j = 0; j < m; j++)
            {
                pre += matrix[j][i];
                s[j + 1][i] = pre;
            }
        }

        set<int> preSet;
        set<int>::iterator it;
        int now = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j <= m; j++)
            {
                preSet.clear();
                preSet.insert(0);
                pre = 0;
                for (int column = 0; column < n; column++)
                {
                    now = s[j][column] - s[i][column];
                    pre += now;

                    it = preSet.lower_bound(pre - k);
                    if (it != preSet.end())
                    {
                        now = pre - *it;
                        if (now == k)
                        {
                            return k;
                        }
                        else if (now > ans)
                        {
                            ans = now;
                        }
                    }
                    preSet.insert(pre);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {
        {2,2,-1},
    };
    cout << s.maxSumSubmatrix(matrix, 0) << endl;
}