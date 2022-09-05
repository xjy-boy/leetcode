#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
private:
    bool isNeighborhood(string gene1, string gene2)
    {
        
        int dif = 0;
        for (int i = 0; i < 8; i++)
        {
            if (gene1[i] != gene2[i])
            {
                dif += 1;
            }
        }
        return dif == 1;
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        int endIndex = -1;
        vector<int> pathLength = vector<int>(bank.size(), -1);
        queue<string> searchQueue;

        for(int i = 0; i < bank.size(); i++)
        {
            if (bank[i] == end)
            {
                endIndex = i;
            }
            if (bank[i] == start)
            {
                pathLength[i] = 0;
            }
        }
        if (endIndex < 0)
        {
            return -1;
        }
        searchQueue.push(start);
        int length = 1;
        while (!searchQueue.empty())
        {
            int size = searchQueue.size();
            for (int i = 0; i < size; i++)
            {
                string now = searchQueue.front();
                searchQueue.pop();
                for (int j = 0; j < bank.size(); j++)
                {
                    if (pathLength[j] >= 0)
                    {
                        continue;
                    }
                    else if (isNeighborhood(now, bank[j]))
                    {
                        if (j == endIndex)
                        {
                            return length;
                        }
                        pathLength[j] = length;
                        searchQueue.push(bank[j]);
                    }
                }
            }
            length += 1;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    string start = "AACCGGTT";
    string end = "AGGCGGTA";
    vector<string> bank = {
        "AACCGGTA","AACCGCTA","AAACGGTA"
    };
    cout << s.minMutation(start, end, bank);
}