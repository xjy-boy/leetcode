#include<iostream>
#include<vector>
#include<random>
#include<numeric>
using namespace std;


class Solution {
public:
    vector<int> fx;
    mt19937 r_eng;
    uniform_int_distribution<int> dis;
    Solution(vector<int>& w):r_eng(random_device{}()){
        int sum = 0;
        for (int &num : w)
        {
            sum += num;
            fx.emplace_back(sum);
        }
        dis = uniform_int_distribution<int>(0, sum);
    }

    int pickIndex() {
        int x = dis(r_eng);
        return lower_bound(fx.begin(), fx.end(), x) - fx.begin();
    }
};

class Solution2 {
private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;

public:
    Solution2(vector<int>& w) : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }

    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};



int main()
{
    vector<int> num = { 1,1 };
    Solution s(num);
    for (int i = 0; i < 100; i++)
    {
        cout << s.pickIndex() << endl;
    }
}