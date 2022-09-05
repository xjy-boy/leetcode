#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> vals;
    vector<vector<int>> memory;

public:
    int maxCoins(vector<int>& nums) {
        vals.emplace_back(1);
        vals.insert(vals.end(), nums.begin(), nums.end());
        vals.emplace_back(1);
        for (int i = 0; i < vals.size(); i++)
        {
            memory.emplace_back(vals.size(), -1);
        }

        return memSearch(0, vals.size() - 1);
    }

    int memSearch(int left, int right)
    {
        if (memory[left][right] >= 0)
        {
            return memory[left][right];
        }
        else if (right <= left + 1)
        {
            return 0;
        }

        int pre = 0;
        int t = 0;
        pre = vals[left] * vals[right];
        for (int i = left + 1; i < right; i++)
        {
            t = vals[i] * pre;
            t += memSearch(left, i);
            t += memSearch(i, right);
            memory[left][right] = max(memory[left][right], t);
        }
        return memory[left][right];
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,1,5,8 };
    cout << s.maxCoins(nums) << endl;
}