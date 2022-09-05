#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int>place;
        unordered_map<int, int>::iterator it;
        int presum = 0;
        int result = 0;
        int length = 0;
        place[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                presum += 1;
            }
            else
            {
                presum -= 1;
            }
            it = place.find(presum);
            if (it == place.end())
            {
                place[presum] = i;
            }
            else
            {
                length = i - it->second;
                result = result > length ? result : length;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 0,1,1,0,1,1,0 };
    Solution solution = Solution();
    cout << solution.findMaxLength(nums) << endl;
}