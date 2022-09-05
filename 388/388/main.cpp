#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        vector<int> length;
        int ans = 0;
        int index = 0;
        while (index < input.size())
        {
            bool isFile = false;

            //层级
            int level = 0;
            while (index < input.size() && input[index] == '\t')
            {
                level += 1;
                index += 1;
            }
            while (level < length.size())
            {
                length.pop_back();
            }

            int nextLength = 0;
            if (!length.empty())
            {
                nextLength = length.back();
            }
            //解析文件名
            while (index < input.size() && input[index] != '\n')
            {
                if (input[index] == '.')
                {
                    isFile = true;
                }
                index += 1;
                nextLength += 1;
            }
            index += 1;
            if (isFile)
            {
                ans = max(ans, nextLength);
            }
            else
            {
                length.emplace_back(nextLength + 1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "file1.txt\nfile2.txt\nlongfile.txt";
    cout << solution.lengthLongestPath(s) << endl;
}