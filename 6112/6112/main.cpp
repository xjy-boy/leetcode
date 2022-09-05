#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int fillCups(vector<int>& amount) {
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int num3 = INT_MIN;
        int sum = 0;
        for (int num : amount)
        {
            if (num > num1)
            {
                num3 = num2;
                num2 = num1;
                num1 = num;
            }
            else if (num > num2)
            {
                num3 = num2;
                num2 = num;
            }
            else if (num > num3)
            {
                num3 = num;
            }
            sum += num;
        }
        int ans = 0;

        if (num1 >= num2 + num3)
        {
            return num1;
        }
        else
        {
            return (sum + 1) / 2;
        }
    }
};

int main()
{
    Solution s;
    vector<int> n = { 7,9,4 };
    cout << s.fillCups(n) << endl;
}