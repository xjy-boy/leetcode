#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = { 0,1 };
        int dif = 2;
        for (int i = 1; i < n; i++)
        {
            for (int j = ans.size() - 1; j >= 0; j--)
            {
                ans.emplace_back(ans[j] + dif);
            }
            dif *= 2;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.grayCode(3);
}