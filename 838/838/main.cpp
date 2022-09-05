#include<iostream>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        int start = 0;
        char now = '.'; //µ±Ç°×´Ì¬
        for (int i = 0; i < dominoes.size(); i++)
        {
            if (dominoes[i] == '.')
            {
                dominoes[i] = now;
            }
            else if (dominoes[i] == 'R')
            {
                now = dominoes[i];
                start = i;
            }
            else
            {
                if (now == '.')
                {

                }
                else
                {
                    int mid = (i + start) / 2;
                    if ((i + start) % 2 == 0)
                    {
                        dominoes[mid] = '.';
                    }
                    start = mid + 1;
                }
                for (int j = start; j < i; j++)
                {
                    dominoes[j] = 'L';
                }
                now = '.';
                start = i + 1;
            }
        }
        return dominoes;
    }
};

int main()
{
    Solution solution = Solution();
    string dominoes = ".L.R...LR..L..";
    cout << solution.pushDominoes(dominoes) << endl;
}