#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> indexMap;
        string word;
        //���ȱ����ַ�����������ӳ��
        for (int i = 0; i < words.size(); i++)
        {
            word = words[i];
            reverse(word.begin(), word.end());
            indexMap[word] = i;
        }
        vector<vector<int>> ans;
        //���������㷨���ÿ���ַ���Ҫ��ɻ��Ĵ�������Ҫ�����к�׺��ǰ׺
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
            //�ҵ�indexλ��Ϊ���ĵ�����Ĵ�
            while (index < word.size())
            {
                //�������㷨ȷ����ʼֵ
                if (index < right)
                {
                    now = min(length[2 * center - index],
                        right - index);
                }
                else
                {
                    now = 1;
                }

                //��չ���Ĵ�
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
                //����center��right
                if (index + now > right)
                {
                    right = index + now;
                    center = index;
                }

                //����ǰλ��Ϊ�����������ַ���Ϊ���Ĵ�
                if (index == word.size() / 2 && index - now < 0
                    && index + now >= word.size())
                {
                    //�ҿ��ַ���
                    if (indexMap.count("") && indexMap[""] != i)
                    {
                        ans.push_back({ indexMap[""],i });
                        ans.push_back({ i,indexMap[""] });
                    }
                }
                else
                {
                    //���Ե�ǰλ��Ϊ���ĵ�����Ĵ��������ַ�����ͷ
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
                    //���Ե�ǰλ��Ϊ���ĵ�����Ĵ��������ַ�����β
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
