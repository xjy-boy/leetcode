#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> wordMap;
        unordered_map<string, char> letterMap;
        int index = 0;
        for (char c : pattern)
        {
            string word = "";
            //解析s中的单词
            if (index >= s.size())
            {
                return false;
            }
            while (index < s.size() && s[index] != ' ')
            {
                word += s[index];
                index += 1;
            }
            index += 1;
            if (wordMap.count(c))
            {
                if (wordMap[c] != word)
                {
                    return false;
                }
            }
            else
            {
                wordMap[c] = word;
            }

            if (letterMap.count(word))
            {
                if (letterMap[word] != c)
                {
                    return false;
                }
            }
            else
            {
                letterMap[word] = c;
            }
        }
        return index > s.size();
    }
};

int main()
{
    string pattern = "he";
    string s = "unit";
    Solution solution;
    solution.wordPattern(pattern, s);
}