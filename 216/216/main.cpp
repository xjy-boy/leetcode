#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> now;
    int sum;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        search(k, n);
        return ans;
    }

    void search(int k,int n) {
        if (now.size() == k)
        {
            if (sum == n)
            {
                ans.emplace_back(now);
            }
        }
        else
        {
            if (now.empty())
            {
                for (int i = 1; i < 10; i++)
                {
                    now.push_back(i);
                    sum = i;
                    search(k, n);
                    now.pop_back();
                }
            }
            else
            {
                for (int i = now.back() + 1; i < 10; i++)
                {
                    now.push_back(i);
                    sum += i;
                    
                    search(k, n);

                    now.pop_back();
                    sum -= i;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    s.combinationSum3(3, 9);
}