#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a[5] = { 0 };
        for (int i = 0; i < text.size(); i++) {
            switch (text[i])
            {
            case 'b':
                a[0] += 1;
                break;
            case 'a':
                a[1] += 1;
                break;
            case 'l':
                a[2] += 1;
                break;
            case 'o':
                a[3] += 1;
                break;
            case 'n':
                a[4] += 1;
                break;
            default:
                break;
            }
        }
        int min = INT_MAX;
        a[2] = a[2] / 2;
        a[3] = a[3] / 2;
        for (int i = 0; i < 5; i++) {
            if (a[i] < min) {
                min = a[i];
            }
        }
        return min;
    }
};

int main() {
    Solution solution = Solution();
    cout << solution.maxNumberOfBalloons("loonbalxballpoon") << endl;
    cout << solution.maxNumberOfBalloons("leetcode") << endl;
    cout << solution.maxNumberOfBalloons("baloon") << endl;
}