#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet;
        unordered_set<string> visit;
        for (string s : deadends) {
            if (s == "0000") {
                return -1;
            }
            deadSet.insert(s);
        }
        queue<string> searchQueue;
        string start = "0000";
        visit.insert(start);
        searchQueue.push(start);
        int length = 0;
        while (!searchQueue.empty()) {
            int size = searchQueue.size();
            length += 1;
            for (int i = 0; i < size; i++) {
                string now = searchQueue.front();
                searchQueue.pop();
                for (int j = 0; j < 4; j++) {
                    string next1 = now;
                    string next2 = now;
                    if (now[j] == '0') {
                        next1[j] = '9';
                    }
                    else {
                        next1[j] -= 1;
                    }

                    if (now[j] == '9') {
                        next2[j] = '0';
                    }
                    else {
                        next2[j] += 1;
                    }

                    if (next1 == target || next2 == target) {
                        return length;
                    }

                    if (!visit.count(next1) && !deadSet.count(next1)) {
                        searchQueue.push(next1);
                        visit.insert(next1);
                    }

                    if (!visit.count(next2) && !deadSet.count(next2)) {
                        searchQueue.push(next2);
                        visit.insert(next2);
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<string> deadends = { "8887","8889","8878","8898","8788","8988","7888","9888" };
    string target = "8888";
    cout << s.openLock(deadends, target);
}