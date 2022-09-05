#include<iostream>
#include<vector>

using namespace std;


class MagicDictionary {
private:
    vector<vector<string>> dict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dict = vector<vector<string>>(100);
    }

    void buildDict(vector<string> dictionary) {
        for (string s : dictionary)
        {
            dict[s.length() - 1].push_back(s);
        }
    }

    bool search(string searchWord) {
        for (string s : dict[searchWord.length() - 1])
        {
            int num = 0;
            for (int i = 0; i < searchWord.length(); i++)
            {
                if (s[i] != searchWord[i])
                {
                    num += 1;
                    if (num > 1)
                    {
                        continue;
                    }
                }
            }
            if (num == 1)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main()
{
    MagicDictionary m;
    vector<string> dict = { "hello","leetcode" };
    m.buildDict(dict);
    cout << m.search("hello") << endl;
    cout << m.search("hhllo") << endl;
    cout << m.search("hell") << endl;
    cout << m.search("leetcoded") << endl;
}