#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> fx;
    int find(int x) 
    {
        int p = x;
        while (fx[p] != p) {
            p = fx[p];
        }
        fx[x] = p;
        return p;
    }

    void join(int x, int y)
    {
        int xParent = find(x);
        int yParent = find(y);
        fx[yParent] = xParent;
        fx[x] = xParent;
        fx[y] = xParent;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        fx = vector<int>();
        for (int i = 0; i < graph.size(); i++) {
            fx.emplace_back(i);
        }

        for (int i = 0; i < graph.size(); i++) {
            int pre = -1;
            for (int j : graph[i]) {
                if (find(i) == find(j)) {
                    return false;
                }
                else if(pre != -1){
                    join(j, pre);
                }
                pre = j;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> graph = { {1,2,3},{0,2},{0,1,3},{0,2} };
    Solution solution;
    cout << solution.isBipartite(graph) << endl;
}