#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


class Solution {
private:
    vector<unordered_map<string, int>> variableStack;
    int now = -1;
    int index = 0;
    string exp;
public:
    int evaluate(string expression) {
        index = 0;
        now = -1;
        exp = expression;
        return evaluateExpression();
    }

    int evaluateExpression() {
        index += 1;
        string prefix = "";
        while (exp[index] != ' ')
        {
            prefix += exp[index];
            index += 1;
        }
        index += 1;
        int res = 0;
        if (prefix == "let")
        {
            variableStack.emplace_back(unordered_map<string,int>());
            now += 1;
            res = evaluateLet();
        }
        else if (prefix == "add")
        {
            res = evaluateMath(1);
        }
        else if (prefix == "mult")
        {
            res = evaluateMath(-1);
        }
        return res;
    }

    int evaluateLet() {
        int res = 0;
        while (index < exp.size())
        {
            //计算let值
            if (exp[index] == '(')
            {
                res = evaluateExpression();
                break;
            }
            //解析变量值
            else if ((exp[index] >= '0' && exp[index] <= '9') || exp[index] == '-')
            {
                res = parseNum();
                break;
            }
            else
            {
                //解析变量符号
                string variables = parseVariale();

                //若为结束
                if (exp[index] == ')')
                {
                    for (int i = variableStack.size() - 1; i >= 0; i--)
                    {
                        if (variableStack[i].count(variables))
                        {
                            res = variableStack[i][variables];
                            break;
                        }
                    }
                    break;
                }
                else if(exp[index] == ' ')
                {
                    index += 1;
                    //解析变量值
                    int num = evaluateVariable();
                    variableStack[now][variables] = num;
                    index += 1;
                }
            }
        }
        now -= 1;
        index += 1;
        variableStack.pop_back();
        return res;
    }
    

    int evaluateMath(int flag){
        int x = 0;
        int y = 0;
        //解析第一个运算符
        x = evaluateVariable();
        index += 1;
        y = evaluateVariable();
        index += 1;

        int res = 0;
        switch (flag)
        {
        case 1:
            res = x + y;
            break;
        case -1:
            res = x * y;
            break;
        default:
            break;
        }
        return res;
    }

    int evaluateVariable() {
        int res = 0;
        if (exp[index] == '(')
        {
            res = evaluateExpression();
        }
        else if ((exp[index] >= '0' && exp[index] <= '9') || exp[index] == '-')
        {
            res = parseNum();
        }
        else
        {
            //解析变量符号
            string variables = parseVariale();
            for (int i = variableStack.size() - 1; i >= 0; i--)
            {
                if (variableStack[i].count(variables))
                {
                    res = variableStack[i][variables];
                    break;
                }
            }
        }
        return res;
    }

    string parseVariale()
    {
        //解析变量符号
        string variables = "";
        while (exp[index] != ' ' && exp[index] != ')')
        {
            variables += exp[index];
            index += 1;
        }
        return variables;
    }

    int parseNum()
    {
        // 解析变量值
        int num = 0;
        int flag = 1;
        if (exp[index] == '-')
        {
            flag = -1;
            index += 1;
        }
        while (exp[index] <= '9' && exp[index] >= '0')
        {
            num = num * 10 + exp[index] - '0';
            index += 1;
        }
        return num * flag;
    }
};

int main()
{
    Solution s;
    string exp = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
    cout << s.evaluate(exp) << endl;
}