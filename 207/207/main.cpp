#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> studyQueue;
        vector<int> preCourse = vector<int>(numCourses, 0);
        int ans = 0;
        vector<vector<int>> graph = vector<vector<int>>(numCourses);
        for (vector<int> prerequisite : prerequisites)
        {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            preCourse[prerequisite[0]] += 1;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (preCourse[i] == 0)
            {
                studyQueue.push(i);
            }
        }

        while (!studyQueue.empty())
        {
            int now = studyQueue.front();
            studyQueue.pop();
            ans += 1;
            for (int next : graph[now])
            {
                preCourse[next] -= 1;
                if (preCourse[next] == 0)
                {
                    studyQueue.push(next);
                }
            }
        }
        return ans == numCourses;
    }
};