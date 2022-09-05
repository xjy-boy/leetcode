#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < arr.size(); i++)
        {
            numMap[arr[i]] = i;
        }
        vector<vector<int>> length = vector<vector<int>>();
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            length.emplace_back(vector<int>(i, 0));
            for (int j = 0; j < i; j++)
            {
                int difference = arr[i] - arr[j];
                if (difference < arr[j] && numMap.count(difference))
                {
                    int index = numMap[difference];
                    length[i][j] = length[j][index] + 1;
                    ans = max(ans, length[i][j]);
                }
            }
        }
        ans += 2;
        return ans > 2  ?  ans :0 ;
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 1,3,7,11,12,14,18 };
    cout << s.lenLongestFibSubseq(arr) << endl;
}