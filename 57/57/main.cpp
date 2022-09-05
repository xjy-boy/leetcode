#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    //找出第一个结束时刻小于或等于newInterval开始时刻的下标
    int getStart(vector<vector<int>>& intervals, vector<int>& newInterval, int left, int right)
    {
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            if (intervals[mid][1] == newInterval[0])
            {
                left = mid;
                break;
            }
            else if (intervals[mid][1] > newInterval[0])
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        return left;
    }

    //找出第一个开始时刻大于或等于newInterval结束时刻的下标
    int getEnd(vector<vector<int>>& intervals, vector<int>& newInterval, int left, int right)
    {
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (intervals[mid][0] == newInterval[1])
            {
                left = mid;
                break;
            }
            else if (intervals[mid][0] < newInterval[1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
        {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        //分多种情况讨论：
        //1. 没有结束时刻小于或等于newInterval开始时刻
        if (intervals[0][1] > newInterval[0])
        {
            //没有开始时刻小于newInterval结束时刻
            if (intervals[0][0] > newInterval[1])
            {
                intervals.insert(intervals.begin(), newInterval);
            }
            //最小的开始时刻等于newInterval结束时刻
            else if (intervals[0][0] == newInterval[1])
            {
                intervals[0][0] = newInterval[0];
            }
            //所有开始时刻小于newInterval结束时刻
            else if (intervals.back()[0] <= newInterval[1])
            {
                int start = min(intervals[0][0], newInterval[0]);
                int end = max(intervals.back()[1], newInterval[1]);
                intervals.clear();
                intervals.push_back({ start,end });
            }
            else
            {
                //找出第一个开始时刻大于或等于newInterval结束时刻的下标
                int index = getEnd(intervals, newInterval, 0, intervals.size() - 1);

                //该开始时刻等于newInterval结束时刻
                if (intervals[index][0] == newInterval[1])
                {
                    //进行合并
                    intervals[index][0] = min(intervals[0][0], newInterval[0]);
                    intervals.erase(intervals.begin(), intervals.begin() + index);
                }
                else
                {
                    //进行合并
                    intervals[0][0] = min(intervals[0][0], newInterval[0]);
                    intervals[0][1] = max(intervals[index - 1][1], newInterval[1]);
                    intervals.erase(intervals.begin() + 1, intervals.begin() + index);
                }
            }
        }
        //2.没有开始时刻大于或等于newInterval结束时刻
        else if (intervals.back()[0] < newInterval[1])
        {
            //没有结束时刻大于newInterval开始时刻
            if (intervals.back()[1] < newInterval[0])
            {
                intervals.emplace_back(newInterval);
            }
            //最大的结束时刻等于newInterval开始时刻
            else if (intervals.back()[1] == newInterval[0])
            {
                intervals[intervals.size()-1][1] = newInterval[1];
            }
            else
            {
                //找出第一个结束时刻小于或等于newInterval开始时刻的下标
                int index = getStart(intervals, newInterval, 0, intervals.size() - 1);

                //该结束时刻等于newInterval开始时刻
                if (intervals[index][1] == newInterval[0])
                {
                    //进行合并
                    intervals[index][1] = max(intervals.back()[1], newInterval[1]);
                    intervals.erase(intervals.begin() + index + 1, intervals.end());
                }
                else
                {
                    //进行合并
                    intervals[intervals.size() - 1][0] = min(intervals[index+1][0], newInterval[0]);
                    intervals[intervals.size() - 1][1] = max(intervals.back()[1], newInterval[1]);
                    intervals.erase(intervals.begin() + index + 1, intervals.end() - 1);
                }
            }
        }
        //3. newIntervals处于interval的中间部分
        else
        {
            //找出第一个结束时刻小于或等于newInterval开始时刻的下标
            int index1 = getStart(intervals, newInterval, 0, intervals.size() - 1);
            //找出第一个开始时刻大于或等于newInterval结束时刻的下标
            int index2 = getEnd(intervals, newInterval, index1 + 1, intervals.size() - 1);
            //该结束时刻等于newInterval开始时刻
            if (intervals[index1][1] == newInterval[0])
            {
                //该开始时刻等于newInterval结束时刻
                if (intervals[index2][0] == newInterval[1])
                {
                    intervals[index1][1] = intervals[index2][1];
                    intervals.erase(intervals.begin() + index1 + 1, intervals.begin() + index2 + 1);
                }
                else
                {
                    intervals[index1][1] = max(intervals[index2 - 1][1], newInterval[1]);
                    intervals.erase(intervals.begin() + index1 + 1, intervals.begin() + index2);
                }
            }
            else
            {
                //该开始时刻等于newInterval结束时刻
                if (intervals[index2][0] == newInterval[1])
                {
                    intervals[index1 + 1][0] = min(intervals[index1 + 1][0],newInterval[0]);
                    intervals[index1 + 1][1] = intervals[index2][1];
                    intervals.erase(intervals.begin() + index1 + 2, intervals.begin() + index2 + 1);
                }
                else
                {
                    //需要插入
                    if (index2 == index1 + 1)
                    {
                        intervals.insert(intervals.begin() + index1 + 1, newInterval);
                    }
                    else
                    {
                        intervals[index1 + 1][0] = min(newInterval[0], intervals[index1 + 1][0]);
                        intervals[index1 + 1][1] = max(newInterval[1], intervals[index2 - 1][1]);
                        intervals.erase(intervals.begin() + index1 + 2, intervals.begin() + index2);
                    }
                }
            }
        }
        return intervals;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = { {0,6},{9,16},{17,17} };
    vector<int> newInterval = { 6,11 };
    s.insert(intervals, newInterval);
}