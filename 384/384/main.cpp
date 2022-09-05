#include<iostream>
#include<vector>

using namespace std;


class Solution {
private:
    vector<int> inital;
public:
    Solution(vector<int>& nums) {
        inital = vector<int>(nums);
    }

    vector<int> reset() {
        return inital;
    }

    vector<int> shuffle() {
        vector<int> ans = vector<int>(inital);
        for (int i = 0; i < ans.size(); i++)
        {
            int index = rand() % ans.size();
            int t = ans[i];
            ans[i] = ans[index];
            ans[index] = t;
        }
        return ans;
    }
};