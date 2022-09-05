#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    bool isDividing(int n)
    {
        int t;
        int x = n;
        while (x != 0)
        {
            t = x % 10;
            if (t == 0 || n % t != 0)
            {
                return false;
            }
            else
            {
                x = (x - t) / 10;
            }
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            if (isDividing(i))
            {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
   s.selfDividingNumbers(21, 21);
}