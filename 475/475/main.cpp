#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int index1 = 0;
        int index2 = 0;
        int ans = INT_MIN;
        int now = INT_MAX;
        while (index1 < houses.size())
        {
            while (index2 < heaters.size() && heaters[index2] <= houses[index1])
            {
                index2 += 1;
            }
            now = INT_MAX;
            if (index2 > 0)
            {
                now = min(now, houses[index1] - heaters[index2 - 1]);
            }
            if (index2 < heaters.size())
            {
                now = min(now, heaters[index2] - houses[index1]);
            }
            ans = max(ans, now);
            index1 += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> houses = { 1,2,3 };
    vector<int> heaters = { 2 };
    cout << s.findRadius(houses, heaters) << endl;
}