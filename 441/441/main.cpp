#include<iostream>

using namespace std;


class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 1;
        while (n >= ans)
        {
            n -= ans;
            ans += 1;
        }
        return ans - 1;
    }
};

int main()
{
    Solution s;
    cout << s.arrangeCoins(5) << endl;
}