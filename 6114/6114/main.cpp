#include<iostream>

using namespace std;


class Solution {
public:
    bool canChange(string start, string target) {
        int index1 = 0;
        int index2 = 0;
        while (index1 < start.size() && index2 < target.size())
        {
            while (index1 < start.size() && start[index1] == '_')
            {
                index1 += 1;
            }

            while (index2 < target.size() && target[index2] == '_')
            {
                index2 += 1;
            }

            if (index1 < start.size() && index2<target.size())
            {
                if (start[index1] != target[index2])
                {
                    return false;
                }
                else if (start[index1] == 'L')
                {
                    if (index1 < index2)
                    {
                        return false;
                    }
                }
                else
                {
                    if (index1 > index2)
                    {
                        return false;
                    }
                }
            }
            else if (index1 >= start.size() && index2 >= target.size())
            {
                break;
            }
            else
            {
                return false;
            }
            index1 += 1;
            index2 += 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string start = "_L__R__R__";
    string target = "L______RR";
    cout << s.canChange(start, target) << endl;
}