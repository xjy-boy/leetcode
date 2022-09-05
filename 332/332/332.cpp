#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> nextCity;
    vector<string> ans;
    void dfs(const string& now) 
    {
        while (nextCity[now].size() > 0)
        {
            string temp = nextCity[now].top();;
            nextCity[now].pop();
            dfs(move(temp));
        }
        ans.emplace_back(now);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (vector<string>& ticket : tickets)
        {
            if (!nextCity.count(ticket[0]))
            {
                nextCity[ticket[0]] = priority_queue<string, vector<string>, greater<string>>();
            }
            nextCity[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> t = {
        {"JFK", "AAA"},
        {"AAA", "JFK"}, 
        {"JFK", "BBB"}};
    s.findItinerary(t);
}