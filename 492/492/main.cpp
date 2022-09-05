#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> constructRectangle(int area) {
        int start = sqrt(area);
        int W = start;
        int L = area / W;
        int mult = L * W;
        while (area % W != 0)
        {
            W -= 1;
            L = area / W;
        }
        return { L,W };
    }
};