#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        //由于必须要做切割所以要做特殊处理
        if (n == 2)
        {
            return 1;
        }
        else if (n == 3)
        {
            return 3;
        }
        int ans = 0;
        int length = 0;
        switch (n % 3)
        {
        case 0:
            ans = 1;             // 最终结果全为3
            length = n / 3;
            break;
        case 2:
            ans = 2;             // 最终结果有一个2
            length = n / 3;
            break;
        case 1:
            ans = 4;             // 最终结果有两个2
            length = (n - 4) / 3;
            break;
        default:
            return -1;
        }
        while (length > 10)
        {
            ans = ans * pow(3, 10);
            ans = ans % 1000000007;
            length -= 10;
        }
        ans = ans * pow(3, length);
        return ans % 1000000007;
    }
};

int main()
{
    Solution s;
    cout << s.cuttingRope(8) << endl;
}