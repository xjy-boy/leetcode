#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] += c;
            if (digits[i] > 9)
            {
                c = 1;
                digits[i] -= 10;
            }
            else
            {
                c = 0;
                break;
            }
        }
        if (c != 0)
        {
            digits.insert(digits.begin(), c);
        }
        return digits;
    }
};