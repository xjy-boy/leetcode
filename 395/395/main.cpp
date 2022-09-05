#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return SlidingWindow(s, k);
    }

    //递归
    int dfs(string s, int left, int right, int k) {
        if (right - left + 1 < k)
        {
            return 0;
        }
        vector<int> count = vector<int>(26, 0);

        //统计每个字符出现的个数
        for (int i = left; i <= right; i++)
        {
            count[s[i] - 'a'] += 1;
        }

        //寻找是否有出现个数小于k且不为0的字符
        char split = ' ';
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0 && count[i] < k)
            {
                split = 'a' + i;
                break;
            }
        }
        //没有出现个数小于k且不为0的字符
        if (split == ' ')
        {
            return right - left + 1;
        }
        
        //递归求解
        int nextLeft = left;
        int nextRight = left;
        int ans = 0;
        while (nextRight <= right)
        {
            //去除连续的字符
            while (nextRight <= right && s[nextRight] == split)
            {
                nextRight += 1;
            }
            if (nextRight > right)
            {
                break;
            }
            nextLeft = nextRight;
            while (nextRight <= right && s[nextRight] != split)
            {
                nextRight += 1;
            }
            ans = max(ans, dfs(s, nextLeft, nextRight - 1, k));
        }
        return ans;
    }

    //滑动窗口
    int SlidingWindow(string s, int k) {
        if (k == 1)
        {
            return s.size();
        }
        int ans = 0;
        for (int i = 1; i <= 26; i++)
        {
            int num = 0;
            int less = 0;
            vector<int> count = vector<int>(26, 0);
            int left = 0;
            int right = 0;
            while (right < s.size())
            {
                count[s[right] - 'a'] += 1;
                //增加了新的字符
                if (count[s[right] - 'a'] == 1)
                {
                    num += 1;
                    less += 1;
                    //滑动左窗口
                    while (num > i)
                    {
                        count[s[left] - 'a'] -= 1;
                        if (count[s[left] - 'a'] == 0)
                        {
                            num -= 1;
                            less -= 1;
                        }
                        else if (count[s[left] - 'a'] == k - 1)
                        {
                            less += 1;
                        }
                        left += 1;
                    }
                }
                else if (count[s[right] - 'a'] == k)
                {
                    less -= 1;
                }
                if (less == 0)
                {
                    ans = max(ans, right - left + 1);
                }
                right += 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "ababbc";
    cout << solution.longestSubstring(s, 2) << endl;
}