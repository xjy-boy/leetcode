#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count = vector<int>(26, 0);
        int ans = 0;
        for (int i = 0; i < s.size();i++)
        {
            count[s[i] - 'a'] += 1;
            while (ans < i && count[s[ans] - 'a'] >= 2)
            {
                ans += 1;
            }
        }
        if (ans >= s.size() || count[s[ans] - 'a'] >= 2)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

int main()
{
    Solution solution;
    string s = "loveleetcode";
    cout << solution.firstUniqChar(s) << endl;
}