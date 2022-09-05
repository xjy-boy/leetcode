#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visit;
    vector<int> parent;
    vector<int> dist;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n);
        visit = vector<bool>(n, false);
        for (vector<int> edge : edges)
        {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        int start = findFarNode(0);
        dist = vector<int>(n, -1);
        parent = vector<int>(n, -1);
        dist[start] = 0;
        dfs(start);
        int end = 0;
        int path = 0;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] > path)
            {
                path = dist[i];
                end = i;
            }
        }
        vector<int> ans;
        for (int i = 0; i < path / 2; i++)
        {
            end = parent[end];
        }
        ans.emplace_back(end);
        if (path % 2 != 0)
        {
            ans.emplace_back(parent[end]);
        }        
        return ans;
    }

    int findFarNode(int n)
    {
        queue<int> searchQueue;
        searchQueue.push(n);
        visit[n] = true;
        int result = n;
        while (!searchQueue.empty())
        {
            int size = searchQueue.size();
            for (int i = 0; i < size; i++)
            {
                int now = searchQueue.front();
                result = now;
                searchQueue.pop();
                for (int next : graph[now])
                {
                    if (visit[next])
                    {
                        continue;
                    }
                    searchQueue.push(next);
                    visit[next] = true;
                }
            }
        }
        return result;
    }

    void dfs(int n)
    {
        for (int next : graph[n])
        {
            if (dist[next] < 0)
            {
                dist[next] = dist[n] + 1;
                parent[next] = n;
                dfs(next);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> e = {
        {0,1} ,{1,2},{1,3},{2,4},{3,5},{4,6}
    };
    s.findMinHeightTrees(7, e);
}