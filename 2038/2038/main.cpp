#include<iostream>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int ans = 0;
        int index = 0;
        while (index < colors.size()) {
            int t = 0;
            while (index < colors.size() && colors[index] == 'A') {
                index += 1;
                t += 1;
            }
            ans += max(0, t - 2);

            t = 0;
            while (index < colors.size() && colors[index] == 'B') {
                index += 1;
                t += 1;
            }
            ans -= max(0, t - 2);
        }
        return ans > 0;
    }
};

int main() {

}