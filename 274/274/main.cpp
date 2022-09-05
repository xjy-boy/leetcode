#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int index = 0;
        while (index<citations.size() && citations.size() - index > citations[index])
        {
            index += 1;
        }
        return citations.size() - index;
    }
};