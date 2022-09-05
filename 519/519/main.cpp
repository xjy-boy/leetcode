#include<iostream>
#include<unordered_map>

using namespace std;


class Solution {
private:
    int row = 0;
    int column = 0;
    int nowSize = 0;
    unordered_map<int, int> symbolMap;
public:
    Solution(int m, int n) {
        row = m;
        column = n;
        nowSize = m * n;
        srand(2);
    }

    vector<int> flip() {
        int index = rand() % nowSize;
        int symbol = index;
        nowSize -= 1;
        if (symbolMap.count(symbol))
        {
            symbol = symbolMap[symbol];
        }
        if (symbolMap.count(nowSize))
        {
            symbolMap[index] = symbolMap[nowSize];
        }
        else
        {
            symbolMap[index] = nowSize;
        }
        return { symbol / column,symbol % column };
    }

    void reset() {
        nowSize = row * column;
        symbolMap.clear();
    }
};

int main()
{
    Solution s(2, 2);
    s.flip();
    s.flip();
    s.flip();
    s.flip();
}
