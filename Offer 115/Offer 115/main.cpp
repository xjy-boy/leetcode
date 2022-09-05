#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        //back[i]中有j表示j在i的后面
        vector<int> preNum = vector<int>(org.size());
        vector<unordered_set<int>> backNum = vector<unordered_set<int>>(org.size());
        unordered_set<int> allNum;
        //构建图并检查数据正确性
        for (vector<int> seq : seqs)
        {
            allNum.insert(seq[0]);
            if (seq[0] > org.size())
            {
                return false;
            }
            for (int i = 0; i < seq.size() - 1; i++)
            {
                allNum.insert(seq[i + 1]);
                if (seq[i + 1] > org.size())
                {
                    return false;
                }
                if (backNum[seq[i] - 1].count(seq[i + 1] - 1))
                {
                    continue;
                }
                preNum[seq[i + 1] - 1] += 1;
                backNum[seq[i] - 1].insert(seq[i + 1] - 1);
            }
        }
        if (allNum.size() != org.size())
        {
            return false;
        }
        queue<int> search;
        int num = 0;
        for (int i = 0; i < org.size(); i++)
        {
            if (preNum[i] == 0)
            {
                search.push(i);
            }
        }
        while (!search.empty() && search.size() == 1)
        {
            int now = search.front();
            search.pop();
            if (now + 1 != org[num])
            {
                return false;
            }
            num += 1;
            for (int next : backNum[now])
            {
                preNum[next] -= 1;
                if (preNum[next] == 0)
                {
                    search.push(next);
                }
            }
        }
        return num == org.size();
    }
};

int main()
{
    vector<int> org = { 5,3,2,4,1 };
    vector<vector<int>> seqs = { {5,3,2,4},{4,1},{1},{3},{2,4},{1,100000} };
    Solution s;
    cout << s.sequenceReconstruction(org, seqs) << endl;
}