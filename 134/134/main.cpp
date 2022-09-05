#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int ans = -1;
        int n = gas.size();
        if (n == 1)
        {
            if (gas[0] < cost[0])
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        gas[n - 1] -= cost[n - 1];
        sum += gas[n - 1];
        cost[n - 1] = -sum;
        for (int i = n - 2; i >= 0; i--)
        {
            gas[i] -= cost[i];
            sum += gas[i];
            //���¸�����վʱ������ cost[i + 1] ����
            if (cost[i + 1] > 0)
            {
                cost[i] = cost[i + 1] - gas[i];
            }
            //ֻҪ�ܵ��¸�����վ����
            else
            {
                cost[i] = -gas[i];
            }
        }
        if (cost[0] > 0)
        {
            cost[n - 1] = cost[0] - gas[n - 1];
        }
        else
        {
            cost[n - 1] = -gas[n - 1];
        }
        if (sum < 0)
        {
            return -1;
        }
        else
        {
            for (int i = 0; i < gas.size(); i++)
            {
                if (cost[i] <= 0)
                {
                    return i;
                }
            }
            return -1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> gas = { 5,1,2,3,4 };
    vector<int> cost = { 4,4,1,5,1 };
    cout << s.canCompleteCircuit(gas, cost) << endl;
}