#include<iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
        {
            return "";
        }
        int mask1[58] = {0};
        int mask2[58] = {0};
        int left = 0;
        int length = 0;
        int resultLeft = 0;
        int resultLength = 0;
        for (int i = 0; i < t.size(); i++)
        {
            mask1[s[i] - 'A'] += 1;
            mask2[t[i] - 'A'] += 1;
        }
        length = t.size();
        //先找到从开头开始的最小窗口
        while (length < s.size() && !has(mask1,mask2))
        {
            mask1[s[length] - 'A'] += 1;
            length += 1;
        }

        //没有找到窗口
        if (!has(mask1, mask2))
        {
            return "";
        }

        //左端缩短窗口
        while (true)
        {
            mask1[s[left] - 'A'] -= 1;
            if (!has(mask1, mask2))
            {
                mask1[s[left] - 'A'] += 1;
                break;
            }
            left += 1;
            length -= 1;
        }
        resultLeft = left;
        resultLength = length;

        //滑动窗口寻找最短串
        while (left + length < s.size())
        {
            mask1[s[left] - 'A'] -= 1;
            mask1[s[left + length] - 'A'] += 1;
            left += 1;

            if (has(mask1, mask2))
            {
                //左端缩短窗口
                while (true)
                {
                    mask1[s[left] - 'A'] -= 1;
                    if (!has(mask1, mask2))
                    {
                        mask1[s[left] - 'A'] += 1;
                        break;
                    }
                    left += 1;
                    length -= 1;
                }
                resultLeft = left;
                resultLength = length;
            }
        }

        return s.substr(resultLeft, resultLength);
    }

    bool has(int mask1[], int mask2[])
    {
        for (int i = 0; i < 58; i++)
        {
            if (mask1[i] < mask2[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "ab";
    string t = "a";
    Solution solution = Solution();
    cout << solution.minWindow(s, t) << endl;
}