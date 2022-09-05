#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int titleToNumber(string columnTitle) {
        vector<int> num = { 308915776, 11881376,456976,17576,676,26,1 };
        vector<int> sum = { 321272406,12356630,475254,18278,702,26,0 };
        int ans = 0;
        int index = 7 - columnTitle.size();
        for (int i = 0; i < columnTitle.size(); i++)
        {
            ans += (columnTitle[i] - 'A' + 1) * num[i + index];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.titleToNumber("AAB") << endl;
}