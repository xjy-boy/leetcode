#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        if (n < 10) {
            return k;
        }
        int high = n;        //n的最高位
        int length = 1;      //n的位数
        int ten = 1;
        while (high >= 10) {
            high /= 10;
            length += 1;
            ten *= 10;
        }
        int forntLength = (ten * 10 - 1) / 9; //high之前的树节点数量
        int behindLength = (ten - 1) / 9; //high之后的树节点数量
        int nowLength = behindLength + n - high * ten + 1; //high对应的树节点数量
        vector<int> allLength;
        for (int i = 0; i < 9; i++) {
            if (i < high - 1) {
                allLength.emplace_back(forntLength);
            }
            else if (i == high - 1) {
                allLength.emplace_back(nowLength);
            }
            else {
                allLength.emplace_back(behindLength);
            }
        }
        int ans = 1;
        for (int i = 0; i < 9; i++) {
            if (k == 1) {
                ans = i + 1;
                break;
            }
            else if (k <= allLength[i]) {
                // 得到结果的最高位,求解下一位
                pair<int, int> res = findKthNumberIncludeZero(allLength[i] - 1, k - 1);
                ans = res.first + (i + 1) * res.second;
                break;
            }
            else {
                k -= allLength[i];
            }
        }
        return ans;
    }

    pair<int,int> findKthNumberIncludeZero(int n, int k) {
        if (n <= 10) {
            return pair<int, int>(k - 1, 10);
        }
        
        //寻找“中间树”
        int temple = n;
        int high = 1; //树的高度
        int length = 10;
        int sum = 0;
        while (sum + length < n) {
            sum += length;
            high += 1;
            length *= 10;
        }
        //此时处于第high层，根据n与sum的差值，可以找出中间树
        length /= 10;
        int mid = (n - sum) / length;

        //mid之前与之后都为完整的树
        int forntLength = (length * 10 - 1) / 9; //mid之前的树节点数量
        int behindLength = (length - 1) / 9; //mid之后的树节点数量
        int nowLength = behindLength + n - sum - mid * length; //mid对应的树节点数量

        vector<int> allLength;
        for (int i = 0; i < 10; i++) {
            if (i < mid) {
                allLength.emplace_back(forntLength);
            }
            else if (i == mid) {
                allLength.emplace_back(nowLength);
            }
            else {
                allLength.emplace_back(behindLength);
            }
        }
        pair<int, int> ans;
        for (int i = 0; i < 10; i++) {
            if (k == 1) {
                ans.first = i;
                ans.second = 10;
                break;
            }
            else if (k <= allLength[i]) {
                pair<int, int> result = findKthNumberIncludeZero(allLength[i] - 1, k - 1);
                ans.first = result.first + i * result.second;
                ans.second = result.second * 10;
                break;
            }
            else {
                k -= allLength[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    for (int i = 1; i <= 100; i++) {
        cout << s.findKthNumber(100, i) << endl;
    }
}