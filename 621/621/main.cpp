#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count = vector<int>(26, 0);
        for (char c : tasks)
        {
            count[c - 'A'] += 1;
        }
        sort(count.begin(), count.end());
        int maxCount = 0;
        int maxNum = 0;
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] > maxNum)
            {
                maxNum = count[i];
                maxCount = 1;
            }
            else if(count[i] == maxNum)
            {
                maxCount += 1;
            }
        }
        return max(
            (maxNum - 1) * (n + 1) + maxCount, 
            static_cast<int>(tasks.size()));
    }
};

int main()
{
    Solution s;
    vector<char> tasks = {
        'A','A','A','B','B','B'
    };
    cout << s.leastInterval(tasks, 2) << endl;
}