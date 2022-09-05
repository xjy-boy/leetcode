#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if (left.empty() && right.empty()) {

        }
        int leftMax = 0;
        int rightMin = n;
        for (int i = 0; i < left.size(); i++) {
            if (left[i] > leftMax) {
                leftMax = left[i];
            }
        }
        for (int i = 0; i < right.size(); i++) {
            if (right[i] < rightMin) {
                rightMin = right[i];
            }
        }

        return max(leftMax, n - rightMin);
    }
};

int main() {
    Solution solution = Solution();
    vector<int> right = { };
    vector<int> left = {0,1,2,3,4,5,6,7};
    int n = 7;
    cout << solution.getLastMoment(n, left, right) << endl;
}