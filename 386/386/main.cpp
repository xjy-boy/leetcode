#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.emplace_back(1);
        while (ans.size() < n)
        {
            int pre = ans.back();
            if (pre * 10 <= n)
            {
                ans.emplace_back(pre * 10);
            }
            else if (pre % 10 != 9 && pre + 1 <= n)
            {
                ans.emplace_back(pre + 1);
            }
            else
            {
                while (pre % 10  == 9 || pre + 1 > n)
                {
                    pre = pre / 10;
                }
                ans.emplace_back(pre + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.lexicalOrder(101);
}