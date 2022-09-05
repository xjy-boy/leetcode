#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int length1 = 0;  //p1p2
        int length2 = 0;  //p2p3
        int length3 = 0;  //p1p3

        //p1p2p3必须是一个等边直角三角形
        length1 = (p1[0] - p2[0]) * (p1[0] - p2[0])
            + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        length2 = (p3[0] - p2[0]) * (p3[0] - p2[0])
            + (p3[1] - p2[1]) * (p3[1] - p2[1]);
        length3 = (p1[0] - p3[0]) * (p1[0] - p3[0])
            + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        if (length1 == 0 || length2 == 0 || length3 == 0)
        {
            return false;
        }
        // p2 为直角点，检测p1p3p4
        else if (length1 == length2 && length3 == length1 + length2)
        {
            length1 = (p1[0] - p4[0]) * (p1[0] - p4[0])
                + (p1[1] - p4[1]) * (p1[1] - p4[1]);
            length2 = (p3[0] - p4[0]) * (p3[0] - p4[0])
                + (p3[1] - p4[1]) * (p3[1] - p4[1]);
        }
        // p3 为直角点，检测p1p2p4
        else if (length2 == length3 && length1 == length2 + length3)
        {
            length3 = length1;
            length1 = (p1[0] - p4[0]) * (p1[0] - p4[0])
                + (p1[1] - p4[1]) * (p1[1] - p4[1]);
            length2 = (p4[0] - p2[0]) * (p4[0] - p2[0])
                + (p4[1] - p2[1]) * (p4[1] - p2[1]);
        }
        // p1 为直角点，检测p2p3p4
        else if (length1 == length3 && length2 == length1 + length3)
        {
            length3 = length2;
            length1 = (p4[0] - p2[0]) * (p4[0] - p2[0])
                + (p4[1] - p2[1]) * (p4[1] - p2[1]);
            length2 = (p3[0] - p4[0]) * (p3[0] - p4[0])
                + (p3[1] - p4[1]) * (p3[1] - p4[1]);
        }
        else
        {
            return false;
        }

        return length1 == length2 && (length3 == length1 + length2);
    }
};


int main()
{
    Solution s;
    vector<int> p1 = { 0,0 };
    vector<int> p2 = { 1,1 };
    vector<int> p3 = { 1,0 };
    vector<int> p4 = { 0,1 };
    s.validSquare(p1, p2, p3, p4);
}