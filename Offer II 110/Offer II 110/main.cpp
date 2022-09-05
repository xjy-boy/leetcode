#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    // 记录每个点已搜索的到N-1的路径
    vector<vector<vector<int>>> path;
    vector<bool> visit;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path = vector<vector<vector<int>>>(graph.size());
        visit = vector<bool>(graph.size(), false);
        findPath(graph, 0);
        for (int i = 0; i < path[0].size(); i++)
        {
            reverse(path[0][i].begin(), path[0][i].end());
        }
        
        return path[0];
    }

    void findPath(vector<vector<int>>& graph,int k) {
        for (int next : graph[k])
        {
            if (next == graph.size() - 1)
            {
                path[k].push_back({next,k});
            }
            else if (visit[next])
            {
                for (vector<int> nextPath : path[next])
                {
                    vector<int> nowPath = vector<int>(nextPath);
                    nowPath.emplace_back(k);
                    path[k].push_back(nowPath);
                }
            }
            else
            {
                findPath(graph, next);
                for (vector<int> nextPath : path[next])
                {
                    vector<int> nowPath = vector<int>(nextPath);
                    nowPath.emplace_back(k);
                    path[k].push_back(nowPath);
                }
            }
        }
        visit[k] = true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    s.allPathsSourceTarget(graph);
}