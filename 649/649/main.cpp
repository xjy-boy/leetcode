#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int num = 0;
        deque<char> searchQueue;
        char next;
        for (char& c : senate)
        {
            searchQueue.push_back(c);
        }

        while (abs(num) != searchQueue.size())
        {
            next = searchQueue.front();
            searchQueue.pop_front();
            if (next == 'R')
            {
                if (num >= 0)
                {
                    searchQueue.push_back(next);
                }
                num += 1;
            }
            else
            {
                if (num <= 0)
                {
                    searchQueue.push_back(next);
                }
                num -= 1;
            }
        }
        if (num < 0)
        {
            return "Dire";
        }
        else
        {
            return "Radiant";
        }
    }
};

int main()
{
    Solution s;
    string input = "RDD";
    cout << s.predictPartyVictory(input) << endl;
}