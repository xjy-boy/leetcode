#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<pair<int, int>> f(1 << n, { INT_MAX, INT_MAX });
        f[0] = { 1, 0 };

        auto add = [&](const pair<int, int>& o, int x) -> pair<int, int> {
            if (o.second + x <= sessionTime) {
                return { o.first, o.second + x };
            }
            return { o.first + 1, x };
        };

        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    f[mask] = min(f[mask], add(f[mask ^ (1 << i)], tasks[i]));
                }
            }
        }
        return f[(1 << n) - 1].first;
    }
};


int main() {
    Solution solution = Solution();
    vector<int> tasks = { 1,1,2,2,2,2,3,3,6,6,6,6 };
    int sessionTime = 10;
    cout << solution.minSessions(tasks, sessionTime) << endl;
}