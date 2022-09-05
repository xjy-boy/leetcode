#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        pair<int, int> n1 = parseString(num1);
        pair<int, int> n2 = parseString(num2);
        string result = "";
        result += to_string(n1.first * n2.first - n1.second * n2.second);
        result += "+";
        result += to_string(n1.first * n2.second + n1.second * n2.first);
        result += "i";
        return result;
    }

    pair<int, int> parseString(string num)
    {
        int result1 = 0;
        int result2 = 0;
        int start = 0;
        int end = 0;
        while (num[end] != '+')
        {
            end += 1;
        }
        result1 = atoi(num.substr(start, end - start).c_str());
        start = end + 1;
        end = start;
        while (num[end] != 'i')
        {
            end += 1;
        }
        result2 = atoi(num.substr(start, end - start).c_str());
        return pair<int, int>(result1, result2);
    }
};

int main()
{
    string num1 = "1+-1i";
    string num2 = "1+-1i";
    Solution solution;
    cout << solution.complexNumberMultiply(num1, num2) << endl;
}