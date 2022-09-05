#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans = vector<int>(a.size(), 1);
        int product = 1;
        for (int i = 0; i < a.size(); i++)
        {
            ans[i] = product;
            product *= a[i];
        }
        product = 1;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            ans[i] *= product;
            product *= a[i];
        }
        return ans;
    }
};