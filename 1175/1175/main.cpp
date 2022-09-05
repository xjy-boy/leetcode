#include<iostream>

using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
    bool isPrime(int n)
    {
        int i = 2;
        while (i * i <= n)
        {
            if (n % i == 0)
            {
                return false;
            }
            i += 1;
        }
        return true;
    }
public:
    int numPrimeArrangements(int n) {
        int num1 = 0;
        int num2 = 0;
        for (int i = 2; i <= n; i++)
        {
            if (isPrime(i))
            {
                num1 += 1;
            }
        }
        num2 = n - num1;
        num1 = max(num1, num2);
        num2 = n - num1;
        long ans = 1;
        for (int i = 2; i <= num2; i++)
        {
            ans = (ans * i) % mod;
            ans = (ans * i) % mod;
        }
        for (int i = num2 + 1; i <= num1; i++)
        {
            ans = (ans * i) % mod;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    //cout << s.numPrimeArrangements(16) << end
    long num = 2612736000;

    cout << num << endl;
    cout << LONG_MAX << endl;
    for (int i = 1; i <= 100; i++)
    {
        //cout << s.numPrimeArrangements(i) << endl;
    }
}