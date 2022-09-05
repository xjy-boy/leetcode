#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
private:
    unordered_map<int, int> indexMap;
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < arr2.size(); i++)
        {
            indexMap[arr2[i]] = i;
        }
        vector<int> last;
        vector<int> count = vector<int>(arr2.size(), 0);
        vector<int> result;
        for (int num : arr1)
        {
            if (indexMap.count(num))
            {
                count[indexMap[num]] += 1;
            }
            else
            {
                last.push_back(num);
            }
        }
        for (int i =0 ; i< count.size();i++)
        {
            
            for (int j = 0; j < count[j]; j++)
            {
                result.push_back(arr2[i]);
            }
        }
        sort(last.begin(), last.end());
        result.insert(result.end(), last.begin(),last.end());
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> arr1 = { 2,3,1,3,2,4,6,7,9,2,19 };
}