#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groupMap;
        vector<vector<int>> ans;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            if (groupSizes[i] == 1)
            {
                ans.emplace_back(1, i);
            }
            else
            {
                if (!groupMap.count(groupSizes[i]))
                {
                    groupMap[groupSizes[i]] = vector<int>();
                }
                groupMap[groupSizes[i]].emplace_back(i);
                if (groupMap[groupSizes[i]].size() == groupSizes[i])
                {
                    ans.emplace_back(groupMap[groupSizes[i]]);
                    groupMap[groupSizes[i]].clear();
                }
            }
        }
        return ans;
    }
};