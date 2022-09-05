#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
private:
    unordered_map<string, int> indexMap;
    vector<unordered_map<int,double>> graph;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        createGraph(equations, values);
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(query(queries[i]));
        }
    }
    
    void createGraph(vector<vector<string>>& equations, vector<double>& values) {
        indexMap.clear();
        graph.clear();
        int index = 0;
        for (int i = 0; i < equations.size(); i++)
        {
            if (!indexMap.count(equations[i][0]))
            {
                indexMap[equations[i][0]] = index;
                graph.emplace_back(unordered_map<int, double>());
                index += 1;
            }

            if (!indexMap.count(equations[i][1]))
            {
                indexMap[equations[i][1]] = index;
                graph.emplace_back(unordered_map<int, double>());
                index += 1;
            }

            int index1 = indexMap[equations[i][0]];
            int index2 = indexMap[equations[i][1]];
            graph[index1][index2] = values[i];
            graph[index2][index1] = 1 / values[i];
        }
    }

    double query(vector<string> querys) {
        int index1 = 0;
        int index2 = 0;
        if (indexMap.count(querys[0]))
        {
            index1 = indexMap[querys[0]];
        }
        else {
            return -1.000000000;
        }

        if (indexMap.count(querys[1]))
        {
            index2 = indexMap[querys[1]];
        }
        else {
            return -1.000000000;
        }

        if (querys[0] == querys[1]) {
            return 1.0000000000000;
        }

        if (!graph[index1].count(index2)) {
            queue<int> search;
            vector<int> visit = vector<int>(graph.size(), false);
            visit[index1] = true;
            for (auto it = graph[index1].begin(); it != graph[index1].end(); it++)
            {
                visit[it->first] = true;
                search.push(it->first);
            }

            while (!search.empty()) {
                int size = search.size();
                for (int i = 0; i < search.size(); i++) {
                    int next = search.front();
                    search.pop();
                    for (auto it = graph[next].begin(); it != graph[next].end(); it++)
                    {
                        if (!visit[it->first]) {
                            visit[it->first] = true;
                            search.push(it->first);
                            double value = graph[index1][next] * it->second;
                            graph[index1][it->first] = value;
                            graph[it->first][index1] = 1 / value;
                        }
                    }
                }
            }
            if (!graph[index1].count(index2)) {
                return -1.00000000000;
            }
        }

        return graph[index1][index2];
    }
};

int main()
{
    Solution s;

    vector<vector<string>> e = { {"a","b"},{"b","c"} };
    vector<double> v = { 2.0,3.0 };
    s.createGraph(e, v);
    cout << s.query({ "a","e" }) << endl;
    cout << s.query({ "a","a" }) << endl;
}