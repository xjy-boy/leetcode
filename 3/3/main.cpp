#include<vector>
#include<unordered_map>
#include<iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int start = 0;
        int i = 0;
        unordered_map<char, int>placeMap;
        while (i < s.size()) {
            while (!placeMap.count(s[i]) && i < s.size()) {
                placeMap[s[i]] = i;
                i++;
            }
            if (i - start > result) {
                result = i - start;
            }
            if (i == s.size()) {
                break;
            }
            else {
                int temple = placeMap[s[i]];
                for (int j = start; j < temple; j++) {
                    placeMap.erase(placeMap.find(s[j]));
                }
                start = temple + 1;
                placeMap[s[i]] = i;
                i++;
            }
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    string s1 = "acbabcbb";
    string s2 = "bbbb";
    string s3 = "";
    string s4 = "ohvhjdml";
    cout << solution.lengthOfLongestSubstring(s1) << endl;
    cout << solution.lengthOfLongestSubstring(s2) << endl;
    cout << solution.lengthOfLongestSubstring(s3) << endl;
    cout << solution.lengthOfLongestSubstring(s4) << endl;
}