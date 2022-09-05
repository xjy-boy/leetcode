#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int target = -1;
        vector<vector<int>> graph;
        vector<bool> visit = vector<bool>(wordList.size(), false);
        vector<int> length = vector<int>(wordList.size(), -1);
        queue<int> q = queue<int>();
        for (int i = 0; i < wordList.size(); i++) {
            graph.emplace_back(vector<int>());
            if (wordList[i] == endWord){
                target = i;
            }
            if (isAdjacent(wordList[i], beginWord)) {
                visit[i] = true;
                length[i] = 1;
                q.push(i);
            }
            for (int j = 0; j < wordList.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (isAdjacent(wordList[i], wordList[j])){
                    graph[i].emplace_back(j);
                }
            }
        }
        if (target < 0) {
            return false;
        }
        while (!visit[target] && !q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int index = q.front();
                q.pop();
                for (int next : graph[index]) {
                    if (visit[next]) {
                        continue;
                    }
                    length[next] = length[index] + 1;
                    visit[next] = true;
                    q.push(next);
                }
            }
        }
        return length[target] + 1;
    }

    bool isAdjacent(string v1, string v2) {
        int d = 0;
        for (int i = 0; i < v1.size(); i++) 
        {
            if (v1[i] != v2[i])
            {
                d++;
            }
            if (d > 1)
            {
                return false;
            }
        }
        return true;
    }
};