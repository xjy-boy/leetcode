#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct MyHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    };
};

class Solution {
private:
    string r;
    string k;
    vector<vector<int>> indexs;
    unordered_map<pair<int, int>, int, MyHash> memory;
    int n = 0;

    int getStep(int nowIndex, int keyIndex)
    {
        if (keyIndex >= k.size())
        {
            return 0;
        }
        pair<int, int> state = { nowIndex,keyIndex };
        if (memory.count(state))
        {
            return memory[state];
        }
        int nextIndex = 0;
        int nextStep = INT_MAX;
        int nextKey = 0;
        nextKey = k[keyIndex] - 'a';
        for (int j = 0; j < indexs[nextKey].size(); j++)
        {
            if (indexs[nextKey][j] == nowIndex)
            {
                nextStep = getStep(nowIndex, keyIndex + 1) + 1;
                break;
            }
            else if (indexs[nextKey][j] > nowIndex)
            {
                nextStep = min(nextStep,
                    min(indexs[nextKey][j] - nowIndex, nowIndex + n - indexs[nextKey][j])
                    + 1 + getStep(indexs[nextKey][j], keyIndex + 1));
            }
            else
            {
                nextStep = min(nextStep,
                    min(nowIndex - indexs[nextKey][j], indexs[nextKey][j] + n - nowIndex)
                    + 1 + getStep(indexs[nextKey][j], keyIndex + 1));
            }
        }
        memory[state] = nextStep;
        return nextStep;
    }
public:
    int findRotateSteps(string ring, string key) {
        r = ring;
        k = key;
        indexs = vector<vector<int>>(26, vector<int>());
        for (int i = 0; i < ring.size(); i++)
        {
            indexs[ring[i] - 'a'].emplace_back(i);
        }
        n = ring.size();
        vector<int> dp = vector<int>(n, 0);
        int nextKey = 0;
        int preKey = 0;
        //±ß½çÌõ¼þ
        nextKey = key[0] - 'a';
        for (int i = 0; i < indexs[nextKey].size(); i++)
        {
            dp[indexs[nextKey][i]] = min(indexs[nextKey][i], n - indexs[nextKey][i]) + 1;
        }

        for (int i = 1; i < key.size(); i++)
        {
            preKey = nextKey;
            nextKey = nextKey = key[i] - 'a';
            if (preKey == nextKey)
            {
                for (int j = 0; j < indexs[nextKey].size(); j++)
                {
                    dp[indexs[nextKey][j]] += 1;
                }
                continue;
            }
            for (int j = 0; j < indexs[nextKey].size(); j++)
            {
                dp[indexs[nextKey][j]] = INT_MAX;
                for (int k = 0; k < indexs[preKey].size(); k++)
                {
                    if (indexs[nextKey][j] > indexs[preKey][k])
                    {
                        dp[indexs[nextKey][j]] = min(dp[indexs[nextKey][j]],
                            dp[indexs[preKey][k]] + min(indexs[nextKey][j] - indexs[preKey][k], n - indexs[nextKey][j] + indexs[preKey][k]) + 1);
                    }
                    else
                    {
                        dp[indexs[nextKey][j]] = min(dp[indexs[nextKey][j]],
                            dp[indexs[preKey][k]] + min(indexs[preKey][k] - indexs[nextKey][j], n + indexs[nextKey][j] - indexs[preKey][k]) + 1);
                    }
                }
            }
        }
        int ans = INT_MAX;
        nextKey = key.back() - 'a';
        for (int i = 0; i < indexs[nextKey].size(); i++)
        {
            ans = min(ans, dp[indexs[nextKey][i]]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string ring = "gdooondg";
    string key = "gdn";
    cout << s.findRotateSteps(ring, key) << endl;
}