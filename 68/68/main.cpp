#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<vector<string>> wordlList;
        vector<int> length;
        int sum = -1;
        wordlList.push_back(vector<string>());
        for (string word : words)
        {
            int nextSum = sum + word.size() + 1;
            if (nextSum > maxWidth)
            {
                length.emplace_back(sum);

                sum = word.size();
                wordlList.push_back(vector<string>());
                wordlList.back().emplace_back(word);
            }
            else
            {
                sum = nextSum;
                wordlList.back().emplace_back(word);
            }
        }

        vector<string> ans;
        for (int i = 0; i < wordlList.size(); i++)
        {
            string result = "";
            if (wordlList[i].size() == 1 || i == wordlList.size()-1)
            {
                result = wordlList[i][0];
                for (int j = 1; j < wordlList[i].size(); j++)
                {
                    result += ' ';
                    result += wordlList[i][j];
                }
                result += string(maxWidth - result.length(), ' ');
            }
            else
            {
                int space = maxWidth - length[i];
                int plus = space % (wordlList[i].size() - 1);
                space = space / (wordlList[i].size() - 1);
                string t = ' ' + string(space, ' ');
                for (int j = 0; j < wordlList[i].size() - 1; j++)
                {
                    result += wordlList[i][j];
                    result += t;
                    if (plus > 0)
                    {
                        result += ' ';
                        plus -= 1;
                    }
                }
                result += wordlList[i].back();
            }
            ans.emplace_back(result);
        }
        return ans;
    }
};
void Func(char str_arg[100]) {
    printf("%d\n", sizeof(str_arg));
}
int main(void) {
    char str[] = "Hello";
    printf("%d\n", sizeof(str));
    printf("%d\n", strlen(str));
    char* p = str;
    printf("%d\n", sizeof(p));
    Func(str);
}