#include<iostream>

using namespace std;


class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() == 1)
        {
            return true;
        }
        bool flag = true;
        if (isLower(word[0]))
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (!isLower(word[i]))
                {
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            if (isLower(word[1]))
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (!isLower(word[i]))
                    {
                        flag = false;
                        break;
                    }
                }
            }
            else
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (isLower(word[i]))
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;
    }

    inline bool isLower(char c)
    {
        return c >= 'a';
    }
};