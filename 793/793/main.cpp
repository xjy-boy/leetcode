#include<iostream>
#include<vector>


class Solution {
public:
    int preimageSizeFZF(int k) {
        //��Ҫô��5Ҫô��0
        //�ɵõ���k��1��ʼ������������ÿ5��ʱ����2��ÿ25��ʱ��3��ÿ100��ʱ��4....
        //�ɴ˿��Ƶ������пɵõ���k

        return help(k + 1) - help(k);
    }

    int zeta(long x) {
        int res = 0;
        while (x) {
            res += x / 5;
            x /= 5;
        }
        return res;
    }


    long long help(int k) {
        long long r = 5LL * k;
        long long l = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (zeta(mid) < k) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return r + 1;
    }

};