#include<iostream>
#include<unordered_map>
using namespace std;


class Solution {
private:
    unordered_map<int, int> ans;
public:
    int integerReplacement(int n) {
        if (n == 1)
        {
            return 0;
        }
        else if (ans.count(n))
        {
            return ans[n];
        }
        else if (n % 2 == 0)
        {
            int res = integerReplacement(n / 2) + 1;
            ans[n] = res;
            return res;
        }
        else
        {
            int res = min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)) + 2;
            ans[n] = res;
            return res;
        }
    }
};

int main()
{
    Solution s;
    cout << s.integerReplacement(3) << endl;
}