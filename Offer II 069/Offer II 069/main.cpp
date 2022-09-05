#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return binarySearch(0, arr.size() - 1, arr);
    }

    int binarySearch(int _left, int _right, vector<int>& arr)
    {
        if (_left == _right)
        {
            return _left;
        }
        else
        {
            int mid = (_left + _right) / 2;
            if (arr[mid] > arr[_left] && arr[mid] > arr[_right])
            {
                int index1 = binarySearch(_left, mid, arr);
                int index2 = binarySearch(mid, _right, arr);
                return arr[index1] > arr[index2] ? index1 : index2;
            }
            else if (arr[mid] == arr[_left])
            {
                return binarySearch(_left, mid, arr);
            }
            else if (arr[mid] == arr[_right])
            {
                return binarySearch(mid , _right, arr);
            }
            else if (arr[mid] > arr[_left] && arr[mid] < arr[_right])
            {
                return binarySearch(mid + 1, _right, arr);
            }
            else
            {
                return binarySearch(_left, mid, arr);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr = { 3,4,5,1 };
    cout << s.peakIndexInMountainArray(arr) << endl;
}