#include<iostream>
#include<vector>
using namespace std;

class MyCalendar {
private:
    vector<int> timeList;
public:
    MyCalendar() {
        timeList = vector<int>();
    }

    bool book(int start, int end) {
        if (timeList.empty())
        {
            timeList.push_back(start);
            timeList.push_back(end);
            return true;
        }
        else if (timeList[0] > end)
        {
            timeList.insert(timeList.begin(), { start,end });
            return true;
        }
        else if (timeList[0] == end)
        {
            timeList[0] = start;
            return true;
        }
        //���������ҵ����±꣬ȷ���Ƿ����Ԥ��
        int left = 0;
        int right = timeList.size() - 1;
        int mid;
        int index = 0;
        while (left < right)
        {
            mid = (left + right + 1) / 2;
            if (timeList[mid] == start)
            {
                left = mid;
                break;
            }
            else if (timeList[mid] > start)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        index = left;
        // timeList[index] Ϊ��һ��С�ڵ���start��ֵ
        //timeList[index]Ϊ��ʼʱ�̣�
        if (index % 2 == 0)
        {
            return false;
        }
        //timeList[index]Ϊ����ʱ�̣�����һ����ʼʱ���Ƿ��end��
        else
        {
            //����Ԥ��
            if (index + 1 == timeList.size())
            {
                //�鿴�Ƿ���Ժϲ�
                // ������ǰ�ϲ�
                if (start == timeList[index])
                {
                    timeList[index] = end;
                }
                else
                {
                    timeList.insert(timeList.begin() + index + 1, { start,end });
                }
                return true;
            }
            else if (timeList[index + 1] >= end)
            {
                //�鿴�Ƿ���Ժϲ�
                // ���������ϲ�Ϊһ��
                if (start == timeList[index] && end == timeList[index + 1])
                {
                    timeList.erase(timeList.begin() + index, timeList.begin() + index + 2);
                }
                // ������ǰ�ϲ�
                else if (start == timeList[index])
                {
                    timeList[index] = end;
                }
                // �������ϲ�
                else if (end == timeList[index + 1])
                {
                    timeList[index + 1] = start;
                }
                // ���ɺϲ�
                else
                {
                    timeList.insert(timeList.begin() + index, { start,end });
                }
                return true;
            }
            return false;
        }
    }
};

int main()
{
    MyCalendar my;
    vector<vector<int>> input = {
{20,29},{13,22},{44,50},{1,7},{2,10},{14,20},{19,25},{36,42},{45,50},{47,50},{39,45},{44,50},{16,25},{45,50},{45,50},{12,20},{21,29},{11,20},{12,17},{34,40},{10,18},{38,44},{23,32},{38,44},{15,20},{27,33},{34,42},{44,50},{35,40},{24,31}
    };
    for (vector<int> i : input)
    {
        if (my.book(i[0], i[1]))
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    
}