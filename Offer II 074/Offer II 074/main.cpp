#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> timeList;
        for (vector<int> timePair : intervals)
        {
            // 第一个大于开始时间的索引
            auto startIndex = lower_bound(timeList.begin(), timeList.end(), timePair[0]);
            if (startIndex == timeList.end())
            {
                timeList.push_back(timePair[0]);
                timeList.push_back(timePair[1]);
                continue;
            }
            // 第一个大于结束时间的索引
            auto endIndex = upper_bound(timeList.begin(), timeList.end(), timePair[1]);
            //分多种情况讨论
            int end = endIndex - timeList.begin();
            int start = startIndex - timeList.begin();            
            if (end == start)
            {
                if (end % 2 == 0)
                {
                    timeList.insert(startIndex, { timePair[0] ,timePair[1] });
                    continue;
                }
            }
            if (end % 2 == 1 && start % 2 == 0)
            {
                timeList[start] = timePair[0];
                if (end - start > 1)
                {
                    timeList.erase(startIndex + 1, endIndex);
                }
            }
            else if (end % 2 == 0 && start % 2 == 0)
            {
                timeList[start] = timePair[0];
                timeList[end - 1] = timePair[1];
                if (end - start > 2)
                {
                    timeList.erase(startIndex + 1, endIndex-1);
                }
            }
            else if (end % 2 == 1 && start % 2 == 1)
            {
                timeList.erase(startIndex, endIndex);
            }
            else if(end % 2 == 0 && start % 2 == 1)
            {
                timeList[end - 1] = timePair[1];
                if (end - start > 1)
                {
                    timeList.erase(startIndex, endIndex - 1);
                }
            }
        }
        vector<vector<int>> result;
        for (int i = 0; i < timeList.size(); i+=2)
        {
            result.push_back({ timeList[i], timeList[i + 1] });
        }
        return result;
    }
};

int main()
{
    Solution s;
    //vector<vector<int>> intervals = { {2,3},{4,6},{5,7},{3,4} };
    //vector<vector<int>> intervals = { {1,4},{0,1}};
    vector<vector<int>> intervals = { {2,3},{5,5},{2,2},{3,4},{3,4} };
    //vector<vector<int>> intervals = { {2,3},{4,5},{6,7},{8,9},{1,10} };
    //vector<vector<int>> intervals = {{5, 5}, {1, 3}, {3, 5}, {4, 6}, {1, 1}, {3, 3}, {5, 6}, {3, 3}, {2, 4}, {0, 0}};
    s.merge(intervals);
}