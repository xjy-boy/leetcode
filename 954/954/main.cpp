#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> number;
        int max = 0;
        for (int num : arr)
        {
            if (number.count(num))
            {
                number[num] += 1;
            }
            else
            {
                number[num] = 1;
            }

            if (abs(num) > max)
            {
                max = abs(num);
            }
        }

        for (int i = 0; i <= max; i++)
        {
            if (number.count(i))
            {
                while (number[i] > 0)
                {
                    number[i] -= 1;
                    if (!number.count(2 * i) || number[2 * i] <= 0)
                    {
                        return false;
                    }
                    else
                    {
                        number[2 * i] -= 1;
                    }
                }
            }
            i = -i;
            if (number.count(i))
            {
                while (number[i] > 0)
                {
                    number[i] -= 1;
                    if (!number.count(2 * i) || number[2 * i] <= 0)
                    {
                        return false;
                    }
                    else
                    {
                        number[2 * i] -= 1;
                    }
                }
            }
            i = -i;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 4,-2,2,-4 };
    s.canReorderDoubled(arr);
}