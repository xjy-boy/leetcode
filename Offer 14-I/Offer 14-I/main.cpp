#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        //���ڱ���Ҫ���и�����Ҫ�����⴦��
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
            ans = 1;             // ���ս��ȫΪ3
            length = n / 3;
            break;
        case 2:
            ans = 2;             // ���ս����һ��2
            length = n / 3;
            break;
        case 1:
            ans = 4;             // ���ս��������2
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