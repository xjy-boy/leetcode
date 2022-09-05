#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                ans = max(ans, (right - left) *  height[left]);
                left += 1;
            }
            else
            {
                ans = max(ans, (right - left) *height[right]);
                right -= 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> n = { 1,8,6,2,5,4,8,3,7 };
    cout << s.maxArea(n) << endl;
}