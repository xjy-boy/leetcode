#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
private:
    int ans =0;
    int *fx = NULL;
    unordered_map<int, int> indexMap;
    void build(int n)
    {
        ans = -1;
        fx = (int *)malloc(sizeof(int) * n);
        if (fx)
        {
            memset(fx, -1, sizeof(int) * n);
        }
    }

    int find(int x)
    {
        int p = x;
        while (fx[p] > 0)
        {
            p = fx[p];
        }
        if (fx[x] > 0)
        {
            fx[x] = p;
        }
        return p;
    }

    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        fx[px] += fx[py];
        ans = min(ans, fx[px]);
        fx[py] = px;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        build(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (indexMap.count(nums[i]))
            {
                continue;
            }
            else
            {
                indexMap[nums[i]] = i;
            }

            if (indexMap.count(nums[i] + 1))
            {
                join(i, indexMap[nums[i] + 1]);
            }

            if (indexMap.count(nums[i] - 1))
            {
                join(i, indexMap[nums[i] - 1]);
            }
        }
        return -ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 100,4,200,1,3,2 };
    cout << s.longestConsecutive(nums) << endl;
}