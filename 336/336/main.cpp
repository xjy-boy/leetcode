#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> indexMap;
        string word;
        //首先保存字符串到索引的映射
        for (int i = 0; i < words.size(); i++)
        {
            word = words[i];
            reverse(word.begin(), word.end());
            indexMap[word] = i;
        }
        vector<vector<int>> ans;
        //用马拉车算法求解每个字符串要组成回文串可能需要的所有后缀与前缀
        int center = 0;
        int right = -1;
        int index = 0;
        int now = 0;
        int nextIndex = 0;
        string next;
        vector<int> length;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].empty())
            {
                continue;
            }
            word = string(words[i].size() * 2 + 1, '#');
            for (int j = 0; j < words[i].size(); j++)
            {
                word[j * 2 + 1] = words[i][j];
            }
            length = vector<int>(word.size(), 0);
            center = 0;
            right = -1;
            index = 0;
            //找到index位置为中心的最长回文串
            while (index < word.size())
            {
                //马拉车算法确定初始值
                if (index < right)
                {
                    now = min(length[2 * center - index],
                        right - index);
                }
                else
                {
                    now = 1;
                }

                //拓展回文串
                while (index - now >= 0 && index + now < word.size())
                {
                    if (word[index - now] == word[index + now])
                    {
                        now += 1;
                    }
                    else
                    {
                        break;
                    }
                }
                length[index] = now;
                //更新center与right
                if (index + now > right)
                {
                    right = index + now;
                    center = index;
                }

                //若当前位置为中心且整个字符串为回文串
                if (index == word.size() / 2 && index - now < 0
                    && index + now >= word.size())
                {
                    //找空字符串
                    if (indexMap.count("") && indexMap[""] != i)
                    {
                        ans.push_back({ indexMap[""],i });
                        ans.push_back({ i,indexMap[""] });
                    }
                }
                else
                {
                    //若以当前位置为中心的最长回文串到达了字符串开头
                    if (index - now < 0 && now != 1)
                    {
                        nextIndex = (index + now) / 2;
                        next = words[i].substr(nextIndex,
                            words[i].size() - nextIndex);
                        if (indexMap.count(next) && indexMap[next] != i)
                        {
                            ans.push_back({ indexMap[next],i });
                        }
                    }
                    //若以当前位置为中心的最长回文串到达了字符串结尾
                    if (index + now >= word.size())
                    {
                        nextIndex = (index - now) / 2 + 1;
                        next = words[i].substr(0,nextIndex);
                        if (indexMap.count(next) && indexMap[next] != i)
                        {
                            ans.push_back({ i,indexMap[next] });
                        }
                    }
                }
                index += 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words =
    {
        "a",""
    };
    s.palindromePairs(words);
}
