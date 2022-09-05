#include<iostream>

using namespace std;
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main()
{
    Solution s;
    cout << s.addDigits(0) << endl;
    cout << s.addDigits(9) << endl;
    cout << s.addDigits(18) << endl;
    cout << s.addDigits(20) << endl;
}