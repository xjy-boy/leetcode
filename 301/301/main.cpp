#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
using namespace std;


class Solution {
public:
    string exp;
    string pattern;
    //��λ��֮�������ŵ�����
    vector<int> left;
    //��λ��֮�������ŵ�����
    vector<int> right;
    unordered_set<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        if (s.empty())
        {
            return { "" };
        }

        int leftNum = 0;
        int rightNum = 0;
        left = vector<int>(s.size(), 0);
        right = vector<int>(s.size(), 0);
        for (int index = 0; index < s.size(); index++)
        {
            if (s[index] == '(')
            {
                leftNum += 1;
            }
            else if (s[index] == ')')
            {
                if (leftNum == 0)
                {
                    rightNum += 1;
                }
                else
                {
                    leftNum -= 1;
                }
            }
        }

        for (int index = s.size()-1; index >= 0; index--)
        {
            if (index != s.size() - 1)
            {
                left[index] = left[index + 1];
                right[index] = right[index + 1];
            }

            if (s[index] == '(')
            {
                left[index] += 1;
            }
            else if (s[index] == ')')
            {
                right[index] += 1;
            }
        }
        pattern = s;
        backtrack(0, leftNum, rightNum);
        vector<string> answer;
        for (auto& e : ans)
        {
            answer.emplace_back(e);
        }
        return answer;
    }

    void backtrack(int index, int leftNum,int rightNum) {
        //����Ƿ���������
        if (index == pattern.size())
        {
            if (leftNum == 0 && rightNum == 0 && isVaild())
            {
                ans.insert(exp);
            }
            return;
        }
        //��֦
        else if (leftNum > left[index] || rightNum > right[index])
        {
            return;
        }
        if (pattern[index] == '(' && leftNum > 0)
        {
            backtrack(index + 1, leftNum - 1, rightNum);
        }
        else if (pattern[index] == ')' && rightNum > 0)
        {
            backtrack(index + 1, leftNum, rightNum - 1);
        }
        exp.push_back(pattern[index]);
        backtrack(index + 1, leftNum, rightNum);
        exp.pop_back();
    }

    bool isVaild() 
    {
        int leftNum = 0;
        int index = 0;
        while (index < exp.size() && leftNum >= 0)
        {
            if (exp[index] == '(')
            {
                leftNum += 1;
            }
            else if (exp[index] == ')')
            {
                leftNum -= 1;
            }
            index += 1;
        }
        return index == exp.size() && leftNum == 0;
    }
};

int main()
{
    Solution s;
    s.removeInvalidParentheses(")(");
}