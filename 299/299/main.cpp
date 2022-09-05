#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> num1 = vector<int>(10, 0);
        vector<int> num2 = vector<int>(10, 0);

        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls += 1;
            }
            num1[secret[i] - '0'] += 1;
            num2[guess[i] - '0'] += 1;
        }
        for (int i = 0; i < 10; i++)
        {
            cows += min(num1[i], num2[i]);
        }
        cows -= bulls;
        string ans;
        ans += to_string(bulls);
        ans += "A";
        ans += to_string(cows);
        ans += "B";
        return ans;
    }
};

int main()
{
    Solution s;
}