#include<iostream>

using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int result = 0;
        int length = s.size();
        int i = 0;
        while(i < length) {
            while (s[i] == ' ' && i < length) {
                i++;
            }
            if (i == length) {
                break;
            }
            while (s[i] != ' ' && i < length){
                i++;
            }
            result += 1;
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    string s = "                ";
    cout << solution.countSegments(s) << endl;
}