#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct State
{
    string board;
    vector<int> hands;

    bool operator == (const State& s) const {
        return board == s.board && hands[0] == s.hands[0]
            && hands[1] == s.hands[1] && hands[2] == s.hands[2]
            && hands[3] == s.hands[3] && hands[4] == s.hands[4];
    }
};

struct Hasher
{
    size_t operator()(const State &s) const{
        return hash<string>()(s.board) * hash<int>()(
            s.hands[0] & s.hands[1] & s.hands[2] &
            s.hands[3] & s.hands[4]);
    }
};

class Solution {
public:
    //memory[i] = v表示在i状态下，将球消除需要的最少球数
    unordered_map<State, int,Hasher> memory;
    vector<char> symbol = {
        'R','Y','B','G','W'
    };
    int findMinStep(string board, string hand) {
        vector<int> hands = vector<int>(5, 0);
        for (char& c : hand)
        {
            if (c == 'R')
            {
                hands[0] += 1;
            }
            else if (c == 'Y')
            {
                hands[1] += 1;
            }
            else if (c == 'B')
            {
                hands[2] += 1;
            }
            else if (c == 'G')
            {
                hands[3] += 1;
            }
            else if (c == 'W')
            {
                hands[4] += 1;
            }
        }
        return dfs(board, hands);
    }
    
    string getDel(string board)
    {
        string res;
        vector<pair<char, int>> st;

        for (auto c : board) {
            while (!st.empty() && c != st.back().first && st.back().second >= 3) {
                st.pop_back();
            }
            if (st.empty() || c != st.back().first) {
                st.push_back({ c,1 });
            }
            else {
                st.back().second++;
            }
        }
        if (!st.empty() && st.back().second >= 3) {
            st.pop_back();
        }
        for (int i = 0; i < st.size(); ++i) {
            for (int j = 0; j < st[i].second; ++j) {
                res.push_back(st[i].first);
            }
        }
        return res;
    }

    int dfs(string &board,vector<int>& hands)
    {
        if (board.empty())
        {
            return 0;
        }
        State s;
        s.board = board;
        s.hands = hands;
        string t;
        //已经搜索过
        if (memory.count(s))
        {
            return memory[s];
        }
        int ans = INT_MAX;
        int res = 0;
        

        for (int i = 0; i < 5; i++)
        {
            //没有该球
            if (hands[i] == 0)
            {
                continue;
            }
            hands[i] -= 1;
            //对于每个可能的插入位置
            for (int j = 0; j <= board.size(); j++)
            {
                if (j > 0 && board[j - 1] == symbol[i])
                {
                    continue;
                }
                if ((j < board.size() && board[j] == symbol[i]) ||
                    (j > 0 && j < board.size() && board[j-1] == board[j]
                    && board[j] != symbol[i]))
                {
                    t = getDel(board.substr(0, j) + symbol[i] + board.substr(j, board.size() - j));
                    if (board == "WWRRBBWW")
                    {
                        res = 1;
                    }
                    if (board == "WWBBWW")
                    {
                        res = 1;
                    }
                    res = dfs(t, hands);
                    if (res != -1)
                    {
                        ans = min(ans, res + 1);
                    }

                }
            }
            hands[i] += 1;
        }
        if (ans == INT_MAX)
        {
            ans = -1;
        }
        memory[s] = ans;
        return ans;
    }
};

int main()
{
    Solution s;
    string board = "WWRRBBWW";
    string hands = "WRBRW";
    cout << s.findMinStep(board, hands) << endl;
}