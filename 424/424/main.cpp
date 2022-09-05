#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count = vector<int>(26, 0);
        //初始化
        char maxChar = 'A';
        for (int i = 0; i < k; i++)
        {
            count[s[i] - 'A'] += 1;
            if (count[s[i] - 'A'] > count[maxChar - 'A'])
            {
                maxChar = s[i];
            }
        }
        int left = 0;
        int right = k;
        int ans = 2;
        while (right < s.size())
        {
           //向右滑
            count[s[right] - 'A'] += 1;
            if (count[s[right] - 'A'] > count[maxChar - 'A'])
            {
                maxChar = s[right];
            }
            right += 1;
            //左侧需要滑动
            if (right - left - count[maxChar - 'A'] > k)
            {
                count[s[left] - 'A'] -= 1;
                left += 1;
                for (int i = 0; i < 26; i++)
                {
                    if (count[i] > count[maxChar - 'A'])
                    {
                        maxChar = i + 'A';
                    }
                }
            }
            else
            {
                ans = max(ans, right - left);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "AABABBA";
    cout << solution.characterReplacement(s, 1) << endl;
}