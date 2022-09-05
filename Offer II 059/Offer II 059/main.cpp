#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int num : nums)
        {
            q.push(num);
        }
        while (q.size() > k)
        {
            q.pop();
        }
    }

    int add(int val) {
        if (q.size() < size)
        {
            q.push(val);
            return q.top();
        }
        else
        {
            if (val <= q.top())
            {
                return q.top();
            }
            else
            {
                q.pop();
                q.push(val);
                return q.top();
            }
        }
    }
};

int main()
{
    vector<int> nums = { 4,5,8,2 };
    KthLargest k = KthLargest(3, nums);
    cout << k.add(3) << endl;
    cout << k.add(5) << endl;
    cout << k.add(10) << endl;
    cout << k.add(9) << endl;
    cout << k.add(4) << endl;
}