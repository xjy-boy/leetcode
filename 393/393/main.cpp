#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        vector<int> pre = {
            1 << 7,
            1 << 6,
            1 << 5,
            1 << 4,
            1 << 3
        };
        int index = 0;
        while (index < data.size())
        {
            int length = 0;
            while (length < pre.size() - 1)
            {
                if (!(data[index] & pre[length]))
                {
                    break;
                }
                length += 1;
            }
            if (length == 1)
            {
                return false;
            }
            else if(length > 0)
            {
                if (data[index] & pre[length])
                {
                    return false;
                }
                length -= 1;
                
            }
            for (int i = 0; i < length; i++)
            {
                index += 1;
                if (index >= data.size())
                {
                    return false;
                }
                else if ((!(data[index] & pre[0]))|| (data[index] & pre[1]))
                {
                    return false;
                }
            }
            index += 1;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> data = { 255 };
    s.validUtf8(data);
}