#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) {
            return 1;
        }
        vector<int> trustNumber(n, 0);
        for (int i = 0; i < trust.size(); i++) {
            trustNumber[trust[i][0] - 1]--;
            trustNumber[trust[i][1] - 1]++;
        }
        for (int i = 0; i < trustNumber.size(); i++) {
            if (trustNumber[i] == n - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution = Solution();
    vector<vector<int>> trust = { {1,2}};
    int n = 2;
    cout << solution.findJudge(n, trust);
}