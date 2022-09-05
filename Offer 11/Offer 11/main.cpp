#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (numbers[mid] == numbers[end])
            {
                end -= 1;
            }
            else
            {
                if (numbers[mid] < numbers[end])
                {
                    end = mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }
        return numbers[start];
    }
};

int main()
{
    Solution s;
    vector<int> nums = { 3,3,1,3 };
    cout << s.minArray(nums) << endl;
}