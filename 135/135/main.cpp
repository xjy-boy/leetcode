#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        int pre = 0;
        int length = 0;
        ans = 1;
        pre = 1;
        length = 0;
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i - 1] <= ratings[i])
            {
                if (ratings[i - 1] == ratings[i])
                {
                    length = 0;
                    pre = 1;
                    ans += 1;
                }
                else
                {
                    if (length != 0)
                    {
                        pre = 1;
                        length = 0;
                    }
                    pre += 1;
                    ans += pre;
                }
            }
            else
            {
                length += 1;
                if (length == pre)
                {
                    length += 1;
                }
                ans += length;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> r = { 4,3,3,2,1};
    Solution s;
    cout << s.candy(r) << endl;
}