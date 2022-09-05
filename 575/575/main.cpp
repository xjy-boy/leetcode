#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> types;
        for (int type : candyType)
        {
            types.insert(type);
        }
        return min(candyType.size() / 2, types.size());
    }
};