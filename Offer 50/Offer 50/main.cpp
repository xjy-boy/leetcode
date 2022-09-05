#include<iostream>
#include<unordered_set>
#include<queue>
using namespace std;


class Solution {
public:
    char firstUniqChar(string s) {
        unordered_set<char> charSet;
        unordered_set<char> queueSet;
        queue<char> ansQueue;
        for (char c : s)
        {
            if (!queueSet.count(c))
            {
                ansQueue.push(c);
                queueSet.insert(c);
            }
            else
            {
                charSet.insert(c);
            }
            
            while (!ansQueue.empty()&&charSet.count(ansQueue.front()))
            {
                ansQueue.pop();
            }
        }
        if (ansQueue.empty())
        {
            return ' ';
        }
        else
        {
            return ansQueue.front();
        }
    }
};

int main()
{
    Solution solution;
    string s = "abaccdeff";
    cout << solution.firstUniqChar(s) << endl;
}