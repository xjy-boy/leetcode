#include<iostream>
#include<vector>
#include<stack>

using namespace std;


class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans = vector<int>(n, 0);
        pair<int, int> pre;
        stack<pair<int,int>> taskStack;
        int taskID = 0;
        int time = 0;
        int index = 0;
        bool isStart = true;
        for (string& s : logs)
        {
            index = 0;
            taskID = 0;
            while (s[index] != ':')
            {
                taskID = taskID * 10 + s[index] - '0';
                index += 1;
            }
            index += 1;
            isStart = s[index] == 's';
            
            while (s[index] != ':')
            {
                index += 1;
            }
            index += 1;
            time = 0;
            while (index < s.size())
            {
                time = time * 10 + s[index] - '0';
                index += 1;
            }

            //任务开始
            if (isStart)
            {
                //若当前栈中有任务
                if (!taskStack.empty())
                {
                    ans[taskStack.top().first] += time - taskStack.top().second;
                }
                pre.first = taskID;
                pre.second = time;
                taskStack.push(pre);
            }
            //任务结束
            else
            {
                ans[taskStack.top().first] += time - taskStack.top().second + 1;
                taskStack.pop();
                if (!taskStack.empty())
                {
                    pre = taskStack.top();
                    taskStack.pop();
                    pre.second = time + 1;
                    taskStack.push(pre);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> logs = {
        "0:start:0","1:start:2","1:end:5","0:end:6"
    };
    s.exclusiveTime(2, logs);
}