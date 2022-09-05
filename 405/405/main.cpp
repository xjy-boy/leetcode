#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<char> symbol = {
        '0','1','2','3','4','5',
        '6','7','8','9','a','b','c','d','e','f'
    };
public:
    string toHex(int num) {
        string ans;
        if (num == 0)
        {
            ans = "0";
        }
        else if (num < 0)
        {
            ans = "";
            num = - (num + 1);
            while (num > 0)
            {
                int next = num % 16;
                num = num / 16;
                ans = symbol[15 - next] + ans;
            }
            while (ans.size() < 8)
            {
                ans = 'f' + ans;
            }
        }
        else
        {
            ans = "";
            while (num > 0)
            {
                int next = num % 16;
                num = num / 16;
                ans = symbol[next] + ans;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.toHex(0) << endl;
}