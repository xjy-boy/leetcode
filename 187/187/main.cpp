#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10)
        {
            return {};
        }
        vector<int> sample = { 1,4,16,64,256,1024,4096,16384,65536,262144 };
        unordered_set<int> codeSet;
        unordered_set<int> ansSet;
        int left = 0;
        int right = 9;
        int code = 0;
        for (int i = 0; i < 10; i++)
        {
            switch (s[i])
            {
            case 'A':
                code += 0;
                break;
            case 'C':
                code += sample[i];
                break;
            case 'G':
                code += 2*sample[i];
                break;
            case 'T':
                code += 3*sample[i];
                break;
            default:
                break;
            }
        }
        codeSet.insert(code);
        right += 1;
        left += 1;
        vector<string> ans;
        while (right < s.size())
        {
            code /= 4;

            switch (s[right])
            {
            case 'A':
                code += 0;
                break;
            case 'C':
                code += 262144;
                break;
            case 'G':
                code += 524288;
                break;
            case 'T':
                code += 786432;
                break;
            default:
                break;
            }
            if (codeSet.count(code))
            {
                if (!ansSet.count(code))
                {
                    ans.emplace_back(s.substr(left, 10));
                    ansSet.insert(code);
                }
            }
            else
            {
                codeSet.insert(code);
            }
            left += 1;
            right += 1;
        }
        return ans;
    }
};

int main()
{
    string s = "AAAAAAAAAAAAA";
    Solution solution;
    solution.findRepeatedDnaSequences(s);
}