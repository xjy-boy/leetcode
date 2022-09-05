#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<bool> column;
    vector<int> place;
    vector<vector<string>> ans;
    string t;
public:
    vector<vector<string>> solveNQueens(int n) {
        column = vector<bool>(n, false);
        t = string(n, '.');
        search(0, n);
        return ans;
    }

    void search(int index,int n)
    {
        if (index == n)
        {
            vector<string> result;
            for (int i = 0; i < n; i++)
            {
                result.emplace_back(t);
                result.back()[place[i]] = 'Q';
            }
            ans.emplace_back(result);
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
    s.solveNQueens(4);
}