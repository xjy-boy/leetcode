#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();

        // ����� 1 �����
        int i = 0;
        while (i < n && (i < 2 || distance[i] > distance[i - 2])) {
            ++i;
        }

        if (i == n) {
            return false;
        }

        // ����� j ���ƶ������
        if ((i == 3 && distance[i] == distance[i - 2])
            || (i >= 4 && distance[i] >= distance[i - 2] - distance[i - 4])) {
            //�޸����
            distance[i - 1] -= distance[i - 3];
        }
        ++i;

        // ����� 2 �����
        while (i < n && distance[i] < distance[i - 2]) {
            ++i;
        }

        return i != n;
    }
};

void main()
{
    Solution s;
    vector<int> dis = {
        1,2,2,3,2,2,
    };
    s.isSelfCrossing(dis);

};