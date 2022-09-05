#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<vector<int>> intermediate;
        vector<int> numVetor1;
        vector<int> numVetor2;
        int c = 0;
        int temple = 0;
        for (int i = 0; i < num1.size(); i++) {
            numVetor1.push_back(num1[i] - 48);
        }
        for (int i = 0; i < num2.size(); i++) {
            numVetor2.push_back(num2[i] - 48);
        }

        for (int i = 0; i < numVetor2.size(); i++) {
            intermediate.push_back(vector<int>());
            if (numVetor2[i] == 0) {
                intermediate[i].push_back(0);
                continue;
            }
            c = 0;
            for (int j = numVetor1.size()-1; j >= 0; j--) {
                temple = numVetor2[i] * numVetor1[j] + c;
                intermediate[i].push_back(temple % 10);
                c = temple / 10;
            }
            if (c != 0) {
                intermediate[i].push_back(c);
            }
            reverse(intermediate[i].begin(), intermediate[i].end());
            intermediate[i].insert(intermediate[i].end(), numVetor2.size() - 1 - i, 0);
        }
        for (int i = 1; i < intermediate.size(); i++) {
            int length = max(intermediate[i].size(), intermediate[i-1].size());
            while (intermediate[i].size() < length) {
                intermediate[i].insert(intermediate[i].begin(), 0);
            }
            while (intermediate[i-1].size() < length) {
                intermediate[i-1].insert(intermediate[i].begin(), 0);
            }
            c = 0;
            for (int j = length - 1; j >= 0; j--) {
                temple = intermediate[i][j] + intermediate[i - 1][j] + c;
                intermediate[i][j] = temple % 10;
                c = temple / 10;
            }
            if (c != 0) {
                intermediate[i].insert(intermediate[i].begin(), c);
            }
        }

        string result = "";
        int index = intermediate.size() - 1;
        for (int i = 0; i < intermediate[index].size(); i++) {
            result.push_back(intermediate[index][i] + 48);
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    string num1 = "0";
    string num2 = "20";
    cout << solution.multiply(num1, num2) << endl;
}