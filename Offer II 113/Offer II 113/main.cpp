#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<bool> learned = vector<bool>(numCourses, false);
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        vector<vector<int>> preGraph = vector<vector<int>>(numCourses);
        queue<int> study;
        for (int i = 0; i < prerequisites.size(); i++)
        {  
            graph[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
            preGraph[prerequisites[i][0]].emplace_back(prerequisites[i][1]);
        }

        for (int i = 0; i < preGraph.size(); i++)
        {
            if (preGraph[i].empty())
            {
                study.push(i);
                learned[i] = true;
            }
        }

        while (!study.empty())
        {
            int size = study.size();
            for (int i = 0; i < size; i++)
            {
                int now = study.front();
                study.pop();
                ans.emplace_back(now);
                //检查当前课程的后续课程是否可修
                for (int next : graph[now])
                {
                    if (learned[next])
                    {
                        continue;
                    }
                    //检查next的先修课程是否都已修习
                    int flag = true;
                    for (int pre : preGraph[next])
                    {
                        if (!learned[pre])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        study.push(next);
                        learned[next] = true;
                    }
                }
            }
        }
        if (ans.size() == numCourses)
        {
            return ans;
        }
        else
        {
            return {};
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pre = { {1,0},{2,0},{3,1},{3,2} };
    s.findOrder(4, pre);
}