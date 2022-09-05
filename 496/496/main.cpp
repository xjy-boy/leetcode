#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ansMap;
        vector<int> ans;
        stack<int> LittleStack;
        for (int num : nums2)
        {
            while (!LittleStack.empty() && num > LittleStack.top())
            {
                ansMap[LittleStack.top()] = num;
                LittleStack.pop();
            }
            LittleStack.push(num);
        }

        for (int num : nums1)
        {
            if (ansMap.count(num))
            {
                ans.emplace_back(ansMap[num]);
            }
            else
            {
                ans.emplace_back(-1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = { 4,1,2 };
    vector<int> nums2 = { 1,3,4,2 };
    s.nextGreaterElement(nums1, nums2);
}