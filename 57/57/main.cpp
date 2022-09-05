#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    //�ҳ���һ������ʱ��С�ڻ����newInterval��ʼʱ�̵��±�
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

    //�ҳ���һ����ʼʱ�̴��ڻ����newInterval����ʱ�̵��±�
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
        //�ֶ���������ۣ�
        //1. û�н���ʱ��С�ڻ����newInterval��ʼʱ��
        if (intervals[0][1] > newInterval[0])
        {
            //û�п�ʼʱ��С��newInterval����ʱ��
            if (intervals[0][0] > newInterval[1])
            {
                intervals.insert(intervals.begin(), newInterval);
            }
            //��С�Ŀ�ʼʱ�̵���newInterval����ʱ��
            else if (intervals[0][0] == newInterval[1])
            {
                intervals[0][0] = newInterval[0];
            }
            //���п�ʼʱ��С��newInterval����ʱ��
            else if (intervals.back()[0] <= newInterval[1])
            {
                int start = min(intervals[0][0], newInterval[0]);
                int end = max(intervals.back()[1], newInterval[1]);
                intervals.clear();
                intervals.push_back({ start,end });
            }
            else
            {
                //�ҳ���һ����ʼʱ�̴��ڻ����newInterval����ʱ�̵��±�
                int index = getEnd(intervals, newInterval, 0, intervals.size() - 1);

                //�ÿ�ʼʱ�̵���newInterval����ʱ��
                if (intervals[index][0] == newInterval[1])
                {
                    //���кϲ�
                    intervals[index][0] = min(intervals[0][0], newInterval[0]);
                    intervals.erase(intervals.begin(), intervals.begin() + index);
                }
                else
                {
                    //���кϲ�
                    intervals[0][0] = min(intervals[0][0], newInterval[0]);
                    intervals[0][1] = max(intervals[index - 1][1], newInterval[1]);
                    intervals.erase(intervals.begin() + 1, intervals.begin() + index);
                }
            }
        }
        //2.û�п�ʼʱ�̴��ڻ����newInterval����ʱ��
        else if (intervals.back()[0] < newInterval[1])
        {
            //û�н���ʱ�̴���newInterval��ʼʱ��
            if (intervals.back()[1] < newInterval[0])
            {
                intervals.emplace_back(newInterval);
            }
            //���Ľ���ʱ�̵���newInterval��ʼʱ��
            else if (intervals.back()[1] == newInterval[0])
            {
                intervals[intervals.size()-1][1] = newInterval[1];
            }
            else
            {
                //�ҳ���һ������ʱ��С�ڻ����newInterval��ʼʱ�̵��±�
                int index = getStart(intervals, newInterval, 0, intervals.size() - 1);

                //�ý���ʱ�̵���newInterval��ʼʱ��
                if (intervals[index][1] == newInterval[0])
                {
                    //���кϲ�
                    intervals[index][1] = max(intervals.back()[1], newInterval[1]);
                    intervals.erase(intervals.begin() + index + 1, intervals.end());
                }
                else
                {
                    //���кϲ�
                    intervals[intervals.size() - 1][0] = min(intervals[index+1][0], newInterval[0]);
                    intervals[intervals.size() - 1][1] = max(intervals.back()[1], newInterval[1]);
                    intervals.erase(intervals.begin() + index + 1, intervals.end() - 1);
                }
            }
        }
        //3. newIntervals����interval���м䲿��
        else
        {
            //�ҳ���һ������ʱ��С�ڻ����newInterval��ʼʱ�̵��±�
            int index1 = getStart(intervals, newInterval, 0, intervals.size() - 1);
            //�ҳ���һ����ʼʱ�̴��ڻ����newInterval����ʱ�̵��±�
            int index2 = getEnd(intervals, newInterval, index1 + 1, intervals.size() - 1);
            //�ý���ʱ�̵���newInterval��ʼʱ��
            if (intervals[index1][1] == newInterval[0])
            {
                //�ÿ�ʼʱ�̵���newInterval����ʱ��
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
                //�ÿ�ʼʱ�̵���newInterval����ʱ��
                if (intervals[index2][0] == newInterval[1])
                {
                    intervals[index1 + 1][0] = min(intervals[index1 + 1][0],newInterval[0]);
                    intervals[index1 + 1][1] = intervals[index2][1];
                    intervals.erase(intervals.begin() + index1 + 2, intervals.begin() + index2 + 1);
                }
                else
                {
                    //��Ҫ����
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