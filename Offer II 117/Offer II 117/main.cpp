#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> fx;

    int find(int x)
    {
        int p = x;
        while (fx[p] != p)
        {
            p = fx[p];
        }
        fx[x] = p;
        return p;
    }

    void join(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px != py)
        {
            fx[py] = px;
            fx[y] = px;
        }
    }

    //判断两个字母异位词是否相似
    bool isSimilar(string& X, string& Y)
    {
        int dif = 0;
        for (int i = 0; i < X.size(); i++)
        {
            if (X[i] != Y[i])
            {
                dif += 1;
            }
            if (dif > 2)
            {
                return false;
            }
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        fx = vector<int>();
        for (int i = 0; i < n; i++)
        {
            fx.emplace_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (find(i) == find(j))
                {
                    continue;
                }
                
                if (isSimilar(strs[i], strs[j]))
                {
                    join(i, j);
                }
            }
        }
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            if (fx[i] == i)
            {
                num += 1;
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<string> strs = { "tars","rats","arts","star" };
    cout << s.numSimilarGroups(strs) << endl;
}