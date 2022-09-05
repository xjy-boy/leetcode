#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    vector<string> nums = {
        "",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen",
    };
    vector<string> numsTen = {
        "",
        "Ten",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety",
    };
public:
    string numberToWords(int num) {
        if (num == 0)
        {
            return "Zero";
        }
        int num4 = num % 1000;
        num /= 1000;
        int num3 = num % 1000;
        num /= 1000;
        int num2 = num % 1000;
        num /= 1000;
        int num1 = num % 1000;

        string ans = "";
        if (num1 != 0)
        {
            ans = parse(num1) + " Billion";
        }

        if (num2 != 0)
        {
            if (!ans.empty())
            {
                ans += " ";
            }
            ans += parse(num2) + " Million";
        }

        if (num3 != 0)
        {
            if (!ans.empty())
            {
                ans += " ";
            }
            ans += parse(num3) + " Thousand";
        }

        if (num4 != 0)
        {
            if (!ans.empty())
            {
                ans += " ";
            }
            ans += parse(num4);
        }

        return ans;
    }

    string parse(int num) {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        num1 = num % 10;
        num /= 10;
        num2 = num % 10;
        num3 = num / 10;

        string ans = "";
        if (num3 != 0)
        {
            ans += nums[num3] + " Hundred" + " ";
        }

        if (num1 == 0 && num2 == 0)
        {
            if (num != 0)
            {
                ans.pop_back();
            }
            return ans;
        }
        else if (num2 <= 1)
        {
            ans += nums[num2 * 10 + num1];
        }
        else
        {
            if (num1 == 0)
            {
                ans += numsTen[num2];
            }
            else
            {
                ans += numsTen[num2] + " " + nums[num1];
            }
        }

        return ans;
    }
};

int main()
{
    cout << INT_MAX << endl;
    Solution s;
    cout << s.numberToWords(1230507) << endl;
    //cout << s.parse(110) << endl;
}