#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return SlidingWindow(s, k);
    }

    //�ݹ�
    int dfs(string s, int left, int right, int k) {
        if (right - left + 1 < k)
        {
            return 0;
        }
        vector<int> count = vector<int>(26, 0);

        //ͳ��ÿ���ַ����ֵĸ���
        for (int i = left; i <= right; i++)
        {
            count[s[i] - 'a'] += 1;
        }

        //Ѱ���Ƿ��г��ָ���С��k�Ҳ�Ϊ0���ַ�
        char split = ' ';
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > 0 && count[i] < k)
            {
                split = 'a' + i;
                break;
            }
        }
        //û�г��ָ���С��k�Ҳ�Ϊ0���ַ�
        if (split == ' ')
        {
            return right - left + 1;
        }
        
        //�ݹ����
        int nextLeft = left;
        int nextRight = left;
        int ans = 0;
        while (nextRight <= right)
        {
            //ȥ���������ַ�
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

    //��������
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
                //�������µ��ַ�
                if (count[s[right] - 'a'] == 1)
                {
                    num += 1;
                    less += 1;
                    //�����󴰿�
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