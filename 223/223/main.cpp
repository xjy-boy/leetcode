#include<iostream>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int dx1 = max(ax1, bx1);
        int dy1 = max(ay1, by1);

        int dx2 = min(ax2, bx2);
        int dy2 = min(ay2, by2);

        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);

        int area = max((dx2 - dx1),0) * max((dy2 - dy1),0);

        return area1 - area + area2;
    }
};

int main()
{
    Solution s;
    cout << s.computeArea(-2,-2,2,2,-1,4,1,6) << endl;
}