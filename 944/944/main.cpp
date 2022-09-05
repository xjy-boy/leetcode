#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int length = strs[0].length();
        int ans = 0;
        for (int i = 0; i < length; i++)
        {
            char pre = 'a';
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] < pre)
                {
                    ans += 1;
                    break;
                }
                pre = strs[j][i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> strs = { "zyx","wvu","tsr" };
    cout << s.minDeletionSize(strs) << endl;
}