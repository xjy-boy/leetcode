#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        if (b == 1) {
            return a;
        }
        
        int sign = 1;
        int result = 0;
        if (a < 0) {
            a = -a;
            sign = -sign;
        }
        if (b < 0) {
            b = -b;
            sign = -sign;
        }
        int i = 0;
        while ((a >> 1) > (b << i) ) {
            i++;
        }
        while (a >= b) {
            while (a < (b << i)) {
                i--;
            }
            result += 1 << i;
            a -= (b << i);
        }

        if (sign > 0) {
            return result;
        }
        else {
            return -result;
        }
    }
};

int main() {
    Solution solution = Solution();
    //cout << solution.divide(2147483647,1) << endl;
    cout << solution.divide(-2147483648,1) << endl;
}