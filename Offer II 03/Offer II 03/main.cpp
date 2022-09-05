#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result = vector<int>(n + 1, 0);
        int bit = 1;
        int shift = 0;
        int length = 0;
        int i = 1; //µ±Ç°Ë÷Òý
        while (i < n + 1) {
            shift = 0;
            length = 1 << (bit - 1);
            while (shift < length && i < n + 1) {
                if (shift >= length/2) {
                    result[i] = result[i - length / 2] + 1;
                }
                else {
                    result[i] = result[i - length / 2];
                }
                i+=1;
                shift+=1;
            }
            bit += 1;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> result = solution.countBits(8);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}