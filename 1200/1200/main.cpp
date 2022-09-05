#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int now = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            int next = arr[i] - arr[i - 1];
            if (next < now)
            {
                now = next;
                ans.clear();
                ans.push_back({ arr[i - 1],arr[i] });
            }
            else if(next == now)
            {
                ans.push_back({ arr[i - 1],arr[i] });
            }
        }
        return ans;
    }
};