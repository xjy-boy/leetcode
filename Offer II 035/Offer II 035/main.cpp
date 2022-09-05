#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        int time = 0;
        for (string s : timePoints)
        {
            time = (s[3] - 48) * 10 + (s[4] - 48) + 
                ((s[0] - 48) * 10 + s[1] - 48) * 60;
            times.push_back(time);
        }
        sort(times.begin(), times.end());
        int min = 1440 - (times[times.size() - 1]
            - times[0]);
        for (int i = 1; i < times.size(); i++)
        {
            time = times[i] - times[i - 1];
            if (time < min)
            {
                min = time;
            }
        }
        return min;
    }
};

int main()
{
    Solution solution = Solution();
    vector<string> timePoints = { "23:59","00:00","00:00"};
    cout << solution.findMinDifference(timePoints) << endl;
}
