#include<vector>
#include<iostream>
#include<unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    string exp;
    vector<string> ans;
    string numString;
    int t = 0;

    vector<string> addOperators(string num, int target) {
        t = target;
        numString = num;
        backtrack(0, 0, 0);
        return ans;
    }

    /// <summary>
    /// 
    /// </summary>
    /// <param name="index">�ݹ������</param>
    /// <param name="res">Ŀǰ�ı��ʽ���</param>
    /// <param name="pre">ǰһ������token����ֵ</param>
    void backtrack(int index, long res, long pre)
    {
        if (index == numString.size())
        {
            if (res == t)
            {
                ans.emplace_back(exp);
            }
            return;
        }
        int preSize = exp.size();
        if (index != 0)
        {
            //ռλ
            exp.push_back(0);
        }
        long val = 0;
        for (int i = index; i < numString.size() &&
            (i == index || numString[index] != '0'); i++)
        {
            val = val * 10 + numString[i] - '0';
            exp.push_back(numString[i]);
            //���ʽ��ͷû�з���
            if (index == 0)
            {
                backtrack(i + 1, val, val);
            }
            else
            {
                //+
                exp[preSize] = '+';
                backtrack(i + 1, res + val, val);

                //-
                exp[preSize] = '-';
                backtrack(i + 1, res - val, -val);

                //*
                exp[preSize] = '*';
                backtrack(i + 1, res - pre + pre * val, pre * val);
            }
        }
        //��ԭexp
        exp.resize(preSize);
    }
};


int main()
{
    Solution s;
    s.addOperators("105",5);
}