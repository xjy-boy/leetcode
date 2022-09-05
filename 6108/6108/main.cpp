#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> table = vector<char>(26, ' ');
        char now = 'a';
        for (char c : key)
        {
            if (c == ' ')
            {
                continue;
            }
            else if (table[c - 'a'] == ' ')
            {
                table[c - 'a'] = now;
                now += 1;
            }

        }

        for (int i = 0; i < message.size(); i++)
        {
            if (message[i] == ' ')
            {
                continue;
            }
            else
            {
                message[i] = table[message[i] - 'a'];
            }
        }
        return message;
    }
};

int main()
{
    Solution s;
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    cout << s.decodeMessage(key, message) << endl;
}