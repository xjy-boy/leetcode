#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<bool> column;
    vector<int> place;
    int ans = 0;
public:
    int totalNQueens(int n) {
        column = vector<bool>(n, false);
        ans = 0;
        for (int i = 0; i < n/ 2; i++)
        {
            place.emplace_back(i);
            column[i] = true;
            search(1, n);
            place.pop_back();
            column[i] = false;
        }
        ans *= 2;
        if (n % 2 != 0)
        {
            place.emplace_back(n / 2);
            column[n / 2] = true;
            search(1, n);
        }
        
        return ans;
    }

    void search(int index, int n)
    {
        if (index == n)
        {
            ans += 1;
            return;
        }


        for (int i = 0; i < n; i++)
        {
            if (column[i])
            {
                continue;
            }
            else
            {
                bool flag = true;
                for (int j = 0; j < place.size(); j++)
                {
                    if (abs(i - place[j]) == index - j)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    place.emplace_back(i);
                    column[i] = true;
                    search(index + 1, n);
                    place.pop_back();
                    column[i] = false;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.totalNQueens(9) << endl;
}