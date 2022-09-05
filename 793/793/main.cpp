#include<iostream>
#include<vector>


class Solution {
public:
    int preimageSizeFZF(int k) {
        //答案要么是5要么是0
        //可得到的k从1开始递增，但是在每5个时会增2，每25个时增3，每100个时增4....
        //由此可推导出所有可得到的k

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