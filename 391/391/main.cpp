#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& v) const {
        return hash<int>()(v.first & v.second);
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>, int> nums;
        long top = rectangles[0][3];
        long bottom = rectangles[0][1];
        long left = rectangles[0][0];
        long right = rectangles[0][2];

        long areas = 0;
        pair<int, int> p1 = pair<int, int>(0, 0); //左上
        pair<int, int> p2 = pair<int, int>(0, 0); //左下
        pair<int, int> p3 = pair<int, int>(0, 0); //右上
        pair<int, int> p4 = pair<int, int>(0, 0); //右下
        for (vector<int>& r : rectangles)
        {
            if (r[0] < left)
            {
                left = r[0];
            }

            if (r[1] < bottom)
            {
                bottom = r[1];
            }

            if (r[2] > right)
            {
                right = r[2];
            }

            if (r[3] > top)
            {
                top = r[3];
            }

            areas += (long)(r[3] - r[1]) * (r[2] - r[0]);
            //统计四个顶点
            p1.first = r[0];
            p1.second = r[3];

            p2.first = r[0];
            p2.second = r[1];

            p3.first = r[2];
            p3.second = r[3];
            
            p4.first = r[2];
            p4.second = r[1];

            if (!nums.count(p1))
            {
                nums[p1] = 0;
            }
            if (!nums.count(p2))
            {
                nums[p2] = 0;
            }
            if (!nums.count(p3))
            {
                nums[p3] = 0;
            }
            if (!nums.count(p4))
            {
                nums[p4] = 0;
            }

            nums[p1] += 1;
            nums[p2] += 1;
            nums[p3] += 1;
            nums[p4] += 1;
            if (nums[p1] > 4 || nums[p2] > 4
                || nums[p3] > 4 || nums[p4] > 4)
            {
                return false;
            }
        }

        p1.first = left;
        p1.second = top;

        p2.first = left;
        p2.second = bottom;

        p3.first = right;
        p3.second = top;

        p4.first = right;
        p4.second = bottom;
        if (!nums.count(p1) || !nums.count(p2) 
            || !nums.count(p3) || !nums.count(p4))
        {
            return false;
        }

        nums.erase(p1);
        nums.erase(p2);
        nums.erase(p3);
        nums.erase(p4);
        if ((top - bottom) * (right - left) != areas)
        {
            return false;
        }
        else
        {
            for (auto &it : nums)
            {
                if (it.second != 2 && it.second != 4)
                {
                    return false;
                }
            }
            return true;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {
        {-100000,-100000,100000,100000},
    };
    s.isRectangleCover(v);
}