#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string compressString(string S) {
        string result = "";
        char now;
        int number;
        int i = 0;
        while (i < S.size()) {
            number = i;
            now = S[i];
            while (S[i] == now && i < S.size()) {
                i++;
            }
            number = i - number;
            result.push_back(now);
            result += to_string(number);
        }
        if (result.size() >= S.size()) {
            return S;
        }
        else {
            return result;
        }
    }
};

int main() {
    Solution solution = Solution();
    string s1 = "aabcccccaaa";
    string s2 = "abbccd";
    string s3 = "";
    cout << solution.compressString(s3) << endl;
}