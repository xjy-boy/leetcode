#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> wordId;
    vector<string> wordMap;
    vector<vector<int>> graph;
    vector<vector<int>> path;
    vector<vector<vector<string>>> stringPath;
    void addWord(string &word,bool isWord)
    {
        if (!wordId.count(word))
        {
            wordId[word] = graph.size();
            if (isWord)
            {
                wordMap.emplace_back(word);
            }
            else
            {
                wordMap.emplace_back("");
            }
            graph.push_back(vector<int>());
        }
    }

    void addEdge(string &word)
    {
        char pre = ' ';
        addWord(word,true);
        int preId = wordId[word];
        int nextId = -1;
        for (char& next : word)
        {
            pre = next;
            next = '#';
            addWord(word, false);
            nextId = wordId[word];
            graph[preId].emplace_back(nextId);
            graph[nextId].emplace_back(preId);

            next = pre;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for (int i = 0; i < wordList.size(); i++)
        {
            addEdge(wordList[i]);
        }
        if (!wordId.count(endWord))
        {
            return {};
        }
        if (!wordId.count(beginWord))
        {
            addEdge(beginWord);
        }
        int startId = wordId[beginWord];
        int endId = wordId[endWord];
        int index = 0;
        path = vector<vector<int>>(graph.size());
        stringPath = vector<vector<vector<string>>>(graph.size());
        stringPath[startId].push_back(vector<string>());
        stringPath[startId][0].emplace_back(beginWord);
        vector<bool> visit = vector<bool>(graph.size(), false);
        queue<int> searchQueue;
        searchQueue.push(startId);
        
        while (!searchQueue.empty())
        {
            index = searchQueue.front();
            searchQueue.pop();
            if (visit[index])
            {
                continue;
            }
            visit[index] = true;
            if (index == endId)
            {
                break;
            }
            for (int next : graph[index])
            {
                if (visit[next])
                {
                    continue;
                }
                path[next].emplace_back(index);
                searchQueue.push(next);
            }
        }
        if (!visit[endId])
        {
            return {};
        }
        getPath(endId);
        return stringPath[endId];
    }

    void getPath(int index)
    {
        for (int& pre : path[index])
        {
            if (stringPath[pre].empty())
            {
                getPath(pre);
            }
            if (wordMap[index].empty())
            {
                for (int i = 0; i < stringPath[pre].size(); i++)
                {
                    stringPath[index].emplace_back(stringPath[pre][i]);
                }
            }
            else
            {
                for (int i = 0; i < stringPath[pre].size(); i++)
                {
                    stringPath[index].emplace_back(stringPath[pre][i]);
                    stringPath[index][stringPath[index].size() - 1].emplace_back(wordMap[index]);
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<string> wordList = {
        "a","b","c"
    };
    s.findLadders("a", "c", wordList);
}