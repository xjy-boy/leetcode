#include<iostream>
#include<vector>
#include<random>
#include<chrono>
using namespace std;

class Solution {
private:
    mt19937 rand_num;
    int sum;
    uniform_int_distribution<unsigned int> dist;
    vector<int> prob;
public:
    Solution(vector<int>& w) {
        sum = 0;
        for (int num : w)
        {
            sum += num;
            prob.push_back(sum);
        }
        dist = uniform_int_distribution<unsigned int>(0, sum);
    }

    int pickIndex() {
        unsigned int p = dist(rand_num) + 1;
        int left = 0;
        int right = prob.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (prob[mid] < p)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};
int main()
{
    vector<int> w = { 1,3 };
    Solution s(w);
    s.pickIndex();
}