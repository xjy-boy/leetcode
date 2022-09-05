#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
        {
            return s;
        }
        string result = "";
        int offset = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++)
        {
            int index = i;
            if (index == 0 || index == numRows - 1)
            {
                while (index < s.length())
                {
                    result += s[index];
                    index += offset;
                }
            }
            else
            {
                while (index < s.length())
                {
                    int index2 = index + offset - 2 * i;
                    result += s[index];
                    if (index2 < s.length())
                    {
                        result += s[index2];
                    }
                    index += offset;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 4;
    cout << solution.convert(s, numRows) << endl;
}