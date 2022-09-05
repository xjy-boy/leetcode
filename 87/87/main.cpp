#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    vector<vector<vector<int>>> mem;
    int tran[26] = { 0 };
    string _s1;
    string _s2;
public:
    bool isScramble(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++)
        {
            mem.push_back(vector<vector<int>>());
            for (int j = 0; j < s2.size(); j++)
            {
                mem[i].push_back(vector<int>(s1.size(), 0));
            }
        }
        _s1 = s1;
        _s2 = s2;
        memset(tran, 0, 26);
        int nums[26] = { 0 };
        for (char c : s1)
        {
            nums[c - 'a'] += 1;
        }
        int next = 1;
        for (int i = 0; i < 26; i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            else
            {
                tran[i] = next;
                next = next * nums[i] + 1;
            }            
        }
        
        for (char c : s2)
        {
            nums[c - 'a'] -= 1;
        }
        for (int i = 0; i < 26; i++)
        {
            if (nums[i] != 0)
            {
                return false;
            }
        }
        return isScramble(0, 0, s1.size());
    }

    bool isScramble(int start1,int start2,int length) {
        if (length == 1)
        {
            return _s1[start1] == _s2[start2];
        }
        else if (mem[start1][start2][length - 1] != 0)
        {
            return mem[start1][start2][length - 1] > 0;
        }
        
        int dif = 0;
        for (int i = 0; i < length - 1; i++)
        {
            dif += tran[_s1[start1 + i] - 'a'];
            dif -= tran[_s2[start2 + i] - 'a'];
            if (dif == 0)
            {
                if (isScramble(start1, start2, i + 1) && isScramble(start1 + i + 1, start2 + i + 1, length - i - 1))
                {
                    mem[start1][start2][length - 1] = 1;
                    return true;
                }
            }
        }
        dif = 0;
        for (int i = 0; i < length-1; i++)
        {
            dif += tran[_s1[start1 + i] - 'a'];
            dif -= tran[_s2[start2 + length - i - 1] - 'a'];
            if (dif == 0)
            {
                if (isScramble(start1, start2 + length - i - 1, i + 1) && isScramble(start1 + i + 1, start2, length - i - 1))
                {
                    mem[start1][start2][length - 1] = 1;
                    return true;
                }
            }
        }
        mem[start1][start2][length - 1] = -1; 
        return false;
    }
};

int main()
{
    Solution s;
    string s1 = "abcde";
    string s2 = "caebd";
    cout << s.isScramble(s1, s2) << endl;
}