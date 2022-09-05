#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int index = 0;
        while (index < chars.size())
        {
            int length = 0;
            char now = chars[index];
            while (index < chars.size() && chars[index] == now)
            {
                index += 1;
                length += 1;
            }
            chars[ans] = now;
            ans += 1;
            if (length != 1)
            {
                string lengthString = to_string(length);
                for (char c : lengthString)
                {
                    chars[ans] = c;
                    ans += 1;
                }
            }
        }

        while (chars.size() > ans)
        {
            chars.pop_back();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<char> chars = {
        'a',
        'b','b','b','b',
        'b','b','b','b',
        'b','b','b','b'
    };
    cout << s.compress(chars) << endl;
}