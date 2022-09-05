#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int ans = -1;
        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < dictionary.size(); i++)
        {
            if (ans >= 0 && dictionary[i].size() < dictionary[ans].size())
            {
                continue;
            }
            index1 = 0;
            index2 = 0;
            while (index1 < s.size() && index2 < dictionary[i].size())
            {
                if (s[index1] == dictionary[i][index2])
                {
                    index2 += 1;
                }
                index1 += 1;
            }
            if (index2 == dictionary[i].size())
            {
                //还没有找到结果
                if (ans < 0)
                {
                    ans = i;
                }
                //长度更长
                else if (dictionary[i].size() > dictionary[ans].size())
                {
                    ans = i;
                }
                //判断字典序
                else
                {
                    for (int j = 0; j < dictionary[ans].size(); j++)
                    {
                        if (dictionary[ans][j] < dictionary[i][j])
                        {
                            break;
                        }
                        else if (dictionary[ans][j] > dictionary[i][j])
                        {
                            ans = i;
                            break;
                        }
                    }
                }
            }
        }
        if (ans < 0)
        {
            return "";
        }
        else
        {
            return dictionary[ans];
        }
    }
};