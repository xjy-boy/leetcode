#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int target = -1;
        vector<vector<int>> graph;
        vector<int> length = vector<int>(wordList.size(), -1);
        queue<int> q = queue<int>();
        for (int i = 0; i < wordList.size(); i++) {
            graph.emplace_back(vector<int>());
            if (wordList[i] == endWord) {
                target = i;
            }
            if (isAdjacent(wordList[i], beginWord)) {
                length[i] = 1;
                q.push(i);
            }
            for (int j = 0; j < i; j++) {
                if (isAdjacent(wordList[i], wordList[j])) {
                    graph[i].emplace_back(j);
                    graph[j].emplace_back(i);
                }
            }
        }
        if (target < 0) {
            return 0;
        }
        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            if (index == target)
            {
                break;
            }
            for (int next : graph[index]) {
                if (length[next] < 0) {
                    length[next] = length[index] + 1;
                    q.push(next);
                }
            }
        }
        return length[target] + 1;
    }

    inline bool isAdjacent(string& v1, string& v2) {
        int d = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                d++;
            }
            if (d > 1)
            {
                break;
            }
        }
        return d == 1;
    }
};

int main()
{
    Solution s;
    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };
    cout << s.ladderLength("hit", "cog", wordList);
}