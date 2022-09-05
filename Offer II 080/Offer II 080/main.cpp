#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temple;
    int max = 0;
    int target = 0;
public:
    vector<vector<int>> combine(int n, int k) {
        max = n;
        target = k;
        result.clear();
        temple.clear();
        dfs(1);
        return result;
    }

    void dfs(int nowIndex)
    {
        if (nowIndex> max)
        {
            return;
        }
        if (max + temple.size() - nowIndex + 1 < target)
        {
            return;
        }
        temple.push_back(nowIndex);
        if (temple.size() == target)
        {
            result.push_back(temple);
        }
        else
        {
            dfs(nowIndex + 1);
        }
        temple.pop_back();
        dfs(nowIndex + 1);
    }
};

int main()
{
    Solution s;
    s.combine(1, 1);
}