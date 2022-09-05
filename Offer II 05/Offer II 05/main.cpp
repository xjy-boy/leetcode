#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        int t = 0;
        vector<int> nums = vector<int>(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                t = words[i][j] - 'a';
                nums[i] = nums[i] | (1 << t);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (!(nums[i] & nums[j])) {
                    t = words[i].size() * words[j].size();
                    if (t > result) {
                        result = t;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector<string> words = { "a","baz","fao","bar","fxya","abcdef" };
    cout << solution.maxProduct(words) << endl;
}