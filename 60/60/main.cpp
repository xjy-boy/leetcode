#include<iostream>
using namespace std;

class Solution {
private:
    int num[8] =
    {
        1,2,6,24,120,720,5040,40320
    };
public:
    string getPermutation(int n, int k) {
        string ans;
        bool visit[9] = { false };
        int next = 0;
        k -= 1;
        for (int i = 0; i < n - 1; i++)
        {
            int index = k / num[n - i - 2];
            next = 0;
            while (true)
            {
                if (!visit[next])
                {
                    if (index == 0)
                    {
                        break;
                    }
                    else
                    {
                        index -= 1;
                    }
                }
                next += 1;
            }
            ans += '1' + next;
            visit[next] = true;
            k = k % num[n - i - 2];
        };

        next = 0;
        while (visit[next])
        {
            next += 1;
        }
        ans += '1' + next;
        return ans;
    }
};

int main()
{
    Solution s;
    for (int i = 1; i <= 24; i++)
    {
        cout << s.getPermutation(4, i) << endl;
    }
    cout << s.getPermutation(4, 24) << endl;
}