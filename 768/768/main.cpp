#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<int> preMax;
    vector<int> lastMin;
public:
    int maxChunksToSorted(vector<int>& arr) {
        preMax = vector<int>(arr.size(), 0);
        lastMin = vector<int>(arr.size(), 0);
        int t = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > t)
            {
                t = arr[i];
            }
            preMax[i] = t;
        }
        t = INT_MAX;
        for (int i = arr.size()-1; i >= 0; i--)
        {
            if (arr[i] < t)
            {
                t = arr[i];
            }
            lastMin[i] = t;
        }
        return maxChunksToSorted(0, arr.size() - 1);
    }
    int maxChunksToSorted(int left,int right) {
        if (left == right)
        {
            return 1;
        }
        else
        {
            for (int i = left; i < right; i++)
            {
                if (preMax[i] <= lastMin[i + 1])
                {
                    return 1 + maxChunksToSorted(i + 1, right);
                }
            }
            return 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = {
        5,4,3,2,1
    };
    cout << s.maxChunksToSorted(arr) << endl;
}