#include<iostream>

using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9;
        }
        int upper = pow(10, n) - 1;
        for (int left = upper;; --left) { // ö�ٻ���������벿��
            long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10; // ��ת��벿�ֵ�������ĩβ����������� p
            }
            for (long x = upper; x * x >= p; --x) {
                if (p % x == 0) { // x �� p ������
                    return p % 1337;
                }
            }
        }
    }
};
