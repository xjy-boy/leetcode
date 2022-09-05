#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int index = INT_MAX;
        unordered_map<string, int> indexMap;
        for (int i = 0; i < list1.size(); i++)
        {
            indexMap[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); i++)
        {
            if (indexMap.count(list2[i]))
            {
                int now = i + indexMap[list2[i]];
                if (now < index)
                {
                    ans.clear();
                    ans.emplace_back(list2[i]);
                    index = now;
                }
                else if (now == index)
                {
                    ans.emplace_back(list2[i]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> list1 = { "Shogun", "KFC" ,"Tapioca Express", "Burger King" };
    vector<string> list2 = { "KFC", "Shogun", "Burger King" };
    Solution s;
    s.findRestaurant(list1, list2);
}