#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<string> ans;
    vector<int> now;
    vector<int> time =
    {
        8,4,2,1,
        32,16,8,4,2,1
    };

    void search(int index)
    {
        if (index >= now.size())
        {
            string result = parse();
            if (!result.empty())
            {
                ans.emplace_back(result);
            }
        }
        else
        {
            int t = now[index];
            int next = 10;
            if (index != 0)
            {
                next = now[index - 1];
            }
            while (true)
            {
                search(index + 1);
                if (now[index] == next - 1)
                {
                    break;
                }
                else
                {
                    now[index] += 1;
                }
            }
            now[index] = t;
        }
    }

    string parse()
    {
        int hour = 0;
        int minute = 0;
        for (int num : now)
        {
            if (num < 4)
            {
                hour += time[num];
            }
            else
            {
                minute += time[num];
            }
        }
        string result = "";
        if (hour < 12 && minute < 60)
        {
            string result1 = "";
            string result2 = "";
            if (hour < 10)
            {
                result1 = "0";
            }
            if (minute < 10)
            {
                result2 = "0";
            }
            result1 += to_string(hour);
            result2 += to_string(minute);
            result = result1 + ":" + result2;
        }
        return result;
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        for (int i = 0; i < turnedOn; i++)
        {
            now.emplace_back(turnedOn - i - 1);
        }
        search(0);
        return ans;
    }
};

int main()
{
    Solution s;
    s.readBinaryWatch(9);
}