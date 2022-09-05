#include<iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int length = max(a.size(), b.size());
        if (a.size() < length){
            a.insert(a.begin(), length - a.size(), 48);
        }
        else{
            b.insert(b.begin(), length - b.size(), 48);
        }
        int c = 0;
        int t = 0;
        int p = 0;
        for (int i = length - 1; i >= 0; i--) {
            p = a[i] + b[i] + c - 96;
            c = p / 2;
            t = p % 2;
            result.push_back(t + 48);
        }
        if (c != 0) {
            result.push_back(49);
        }
        reverse(result.rbegin(), result.rend());
        return result;
    }
};

int main() {
    Solution solution = Solution();
    string a = "1010";
    string b = "11";
    cout << solution.addBinary(a, b) << endl;
}