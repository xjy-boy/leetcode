#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<bool> has;
    vector<vector<int>> bigger;
    vector<vector<int>> smaller;
public:
    string alienOrder(vector<string>& words) {
        has = vector<bool>(26, false);
        bigger = vector<vector<int>>(26);
        //bigger[i]中有j表示j比i大
        smaller = vector<vector<int>>(26);
        //smaller[i]中有j表示j比i小
        int num = 0;
        //预处理
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                words[i][j] -= 'a';
            }
        }

        //构建smaller与bigger
        for (int i = 0; i < words.size(); i++)
        {
            for (char c : words[i])
            {
                if (!has[c])
                {
                    has[c] = true;
                    num += 1;
                }
            }
            for (int j = i + 1; j < words.size(); j++)
            {
                if (!add(words[i], words[j]))
                {
                    return "";
                }
            }
        }

        // 求解顺序
        queue<int> search;
        vector<bool> visit = vector<bool>(26, false);
        string ans = "";
        for (int i = 0; i < smaller.size(); i++)
        {
            if (smaller[i].empty() && has[i])
            {
                search.push(i);
                visit[i] = true;
            }
        }

        while (!search.empty())
        {
            int size = search.size();
            for (int i = 0; i < size; i++)
            {
                int now = search.front();
                search.pop();
                ans += now + 'a';
                //检测后续节点
                for (int next : bigger[now])
                {
                    if (visit[next])
                    {
                        continue;
                    }
                    int flag = true;
                    for (int pre : smaller[next])
                    {
                        if (!visit[pre])
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        search.push(next);
                        visit[next] = true;
                    }
                }
            }
        }
        if (ans.size() == num)
        {
            return ans;
        }
        else
        {
            return "";
        }
    }

    bool add(string &small, string &big)
    {
        int i = 0;
        while (i < small.size() && i < big.size())
        {
            if (small[i] != big[i])
            {
                bigger[small[i]].emplace_back(big[i]);
                smaller[big[i]].emplace_back(small[i]);
                return true;
            }
            i += 1;
        }
        if (small.size() > big.size())
        {
            return false;
        }
        else {
            return true;
        }
    }
};

int main()
{
    Solution s;
    vector<string> words = { "z","x","z"};
    cout << s.alienOrder(words) << endl;
}