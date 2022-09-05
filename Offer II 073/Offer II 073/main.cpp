#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int num : piles)
        {
            if (num > right)
            {
                right = num;
            }
        }
        if (piles.size() == h)
        {
            return right;
        }

        while (left < right)
        {
            int mid = (left + right) / 2;
            int result = 0;
            for (int num : piles)
            {
                result += (num - 1) / mid + 1;
            }
            if (result <= h)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution s;
    vector<int> pile = { 312884470 };
    int h = 968709470;
    cout << s.minEatingSpeed(pile, h) << endl;
}