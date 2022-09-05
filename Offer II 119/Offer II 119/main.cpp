#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> fx;
    vector<int> length;
    int ans = 0;
    int find(int x)
    {
        int p = x;
        while (fx[p] != p)
        {
            p = fx[p];
        }
        fx[x] = p;
        return p;
    }

    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            fx[py] = px;
            fx[y] = px;
        }
        length[px] += length[py];
        ans = max(ans, length[px]);
    }

public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        fx = vector<int>();
        length = vector<int>();
        ans = 1;
        for (int i = 0; i < n + 1; i++)
        {
            fx.emplace_back(i);
            length.emplace_back(1);
        }
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            if (index.count(nums[i]))
            {
                continue;
            }
            index[nums[i]] = i;
            if (index.count(nums[i] + 1))
            {
                join(i, index[nums[i] + 1]);
            }

            if (index.count(nums[i] - 1))
            {
                join(i, index[nums[i] - 1]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 0,3,7,2,5,8,4,6,0,1 };
    cout << s.longestConsecutive(nums) << endl;
}