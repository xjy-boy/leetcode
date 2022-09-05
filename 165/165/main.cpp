#include<iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0;
        int index2 = 0;
        while (index1 < version1.size() && index2 < version2.size())
        {
            int num1 = 0;
            int num2 = 0;
            while (index1 < version1.size() && version1[index1] != '.')
            {
                num1 = num1 * 10 + version1[index1] - '0';
                index1 += 1;
            }

            while (index2 < version2.size() && version2[index2] != '.')
            {
                num2 = num2 * 10 + version2[index2] - '0';
                index2 += 1;
            }

            index1 += 1;
            index2 += 1;
            if (num1 < num2)
            {
                return -1;
            }
            else if (num1 > num2)
            {
                return 1;
            }
        }
        if (index1 >= version1.size() && index2 >= version2.size())
        {
            return 0;
        }
        else
        {
            if (index1 >= version1.size())
            {
                for (int i = index2; i < version2.size(); i++)
                {
                    if (version2[i] != '.' && version2[i] != '0')
                    {
                        return -1;
                    }
                }
                return 0;
            }
            else
            {
                for (int i = index1; i < version1.size(); i++)
                {
                    if (version1[i] != '.' && version1[i] != '0')
                    {
                        return 1;
                    }
                }
                return 0;
            }
        }
    }
};

int main()
{
    cout << INT_MAX << endl;
    Solution s;
    string version1 = "1.2147483647";
    string version2 = "1.2147483647";
    cout << s.compareVersion(version1, version2);
}