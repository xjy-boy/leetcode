#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2)
        {
            return points.size();
        }
        unordered_set<int> visit;
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int index = i * n + j;
                if (visit.count(index))
                {
                    continue;
                }
                int now = 2;
                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    else if ((points[k][0] - points[i][0]) *
                        (points[k][1] - points[j][1]) ==
                        (points[k][0] - points[j][0]) *
                        (points[k][1] - points[i][1]))
                    {
                        now += 1;
                        visit.insert(k * n + i);
                        visit.insert(k * n + j);
                        visit.insert(i * n + k);
                        visit.insert(j * n + k);
                    }
                }
                ans = max(ans, now);
                if (ans > n / 2)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points;
}