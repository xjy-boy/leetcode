#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result = vector<int>(temperatures.size(), 0);
        stack<int> smallerStack;
        smallerStack.push(0);
        for (int i = 1; i < temperatures.size(); i++)
        {
            if (temperatures[i] <= temperatures[smallerStack.top()])
            {
                smallerStack.push(i);
            }
            else
            {
                while (!smallerStack.empty()&&temperatures[smallerStack.top()] < temperatures[i])
                {
                    result[smallerStack.top()] = i - smallerStack.top();
                    smallerStack.pop();
                }
                smallerStack.push(i);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> temperatures = { 3,4,5 };
    Solution solution = Solution();
    vector<int> result = solution.dailyTemperatures(temperatures);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
}