#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
private:
    string next;
    unordered_map<long, int> index;
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
        {
            return "0";
        }
        string ans;
        if ((numerator < 0) ^ (denominator < 0))
        {
            ans = "-";
        }
        long n1 = numerator;
        long d1 = denominator;

        if (n1 < 0)
        {
            n1 = -n1;
        }
        if (d1 < 0)
        {
            d1 = -d1;
        }
        
        long num = n1 / d1;
        ans += to_string(num);
        long denum = n1 % d1;
        if (denum != 0)
        {
            int start = getDecimal(denum, d1);
            ans += '.';
            if (start < 0)
            {
                ans += next;
            }
            else
            {
                ans += next.substr(0, start);
                ans += '(';
                ans += next.substr(start, next.size() - start);
                ans += ')';
            }
        }

        return ans;
    }

    int getDecimal(long numerator, long denominator) {
        if (numerator == 0)
        {
            return -1;
        }
        else if (index.count(numerator))
        {
            return index[numerator];
        }

        long num = numerator * 10 / denominator;
        index[numerator] = next.size();
        next += num + '0';


        numerator = numerator * 10 % denominator;
        return getDecimal(numerator, denominator);
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(-2147483648,1) << endl;
}