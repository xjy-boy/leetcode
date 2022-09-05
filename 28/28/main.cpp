#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        vector<int> next = vector<int>(needle.size(), 0);
        next[0] = -1;
        //KMP
        int j = 0;
        int k = -1;
        while (j < needle.size() - 1)
        {
            if (k == -1 || needle[j] == needle[k])
            {
                next[++j] = ++k;
                
            }
            else
            {
                k = next[k];
            }
        }
        //改进的KMP算法
        for (int i = 1; i < needle.size(); i++)
        {
            int k = next[i];
            if (next[k]>=0 && needle[k] == needle[i])
            {
                next[i] = next[k];
            }
        }
        int index = 0;
        int needleIndex = 0;
        while (index <= haystack.size() - needle.size())
        {
            if (needleIndex == -1 || haystack[index + needleIndex] == needle[needleIndex])
            {
                needleIndex += 1;
                if (needleIndex == needle.size())
                {
                    return index;
                }
            }
            else
            {
                index = index + needleIndex - next[needleIndex];
                needleIndex = next[needleIndex];
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string s1 = "babba";
    string s2 = "bbb";
    cout << s.strStr(s1, s2) << endl;
}