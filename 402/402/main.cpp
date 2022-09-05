#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int t = k;
        int left = -1;
        int right = 0;
        vector<bool> save = vector<bool>(num.size(), true);
        while (right < num.size())
        {
            //ɾȥnum[left]
            while (t != 0 && left >= 0 && num[left] > num[right])
            {
                if (save[left])
                {
                    t -= 1;
                }
                save[left] = false;
                left -= 1;
            }
            left = right;
            right += 1;
        }
        int index = 0;
        int size = 0;
        while (size < num.size() - k)
        {
            if (save[index])
            {
                size += 1;
                if (!ans.empty() || num[index] != '0')
                {
                    ans += num[index];
                }
            }
            index += 1;
        }
        if (ans.empty())
        {
            ans = "0";
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string num = "10200";
    cout << s.removeKdigits(num, 2) << endl;
}