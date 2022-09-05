#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int t = 1 << 31;
        bool insert = true;
        for (int asteroid : asteroids)
        {
            insert = true;
            while (!ans.empty() && asteroid < 0 && ans.back()>0)
            {
                if (-asteroid > ans.back())
                {
                    ans.pop_back();
                }
                else if (abs(asteroid) == abs(ans.back()))
                {
                    ans.pop_back();
                    insert = false;
                    break;
                }
                else
                {
                    insert = false;
                    break;
                }
            }
            if (insert)
            {
                ans.emplace_back(asteroid);
            }
        }
        return ans;
    }
};