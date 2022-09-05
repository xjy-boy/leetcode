#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < score.size(); i++)
        {
            indexMap[score[i]] = i;
        }
        sort(score.rbegin(), score.rend());
        vector<string> ans = vector<string>(score.size());
        
        ans[indexMap[score[0]]] = "Gold Medal";
        if (score.size() > 1)
        {
            ans[indexMap[score[1]]] = "Silver Medal";
        }
        if (score.size() > 2)
        {
            ans[indexMap[score[2]]] = "Bronze Medal";
        }
        for (int i = 3; i < score.size(); i++)
        {
            ans[indexMap[score[i]]] = to_string(i + 1);
        }
        return ans;
    }
};