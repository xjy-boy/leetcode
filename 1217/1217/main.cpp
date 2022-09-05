#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ans1 = 0;
        int ans2 = 0;
        for (int num : position)
        {
            if (num % 2 == 1)
            {
                ans1 += 1;
            }
            else
            {
                ans2 += 1;
            }
        }
        return min(ans1, ans2);
    }
};

int main()
{

}