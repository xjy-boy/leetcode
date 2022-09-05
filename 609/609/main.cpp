#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, int> indexMap;
        vector<vector<string>> ans;
        vector<vector<string>> res;
        int index = 0;
        int preIndex = 0;
        string filename;
        string content;
        string pre;
        for (int i = 0; i < paths.size(); i++)
        {
            index = 0;
            //解析前缀
            while (index < paths[i].size() && paths[i][index] != ' ')
            {
                index += 1;
            }
            pre = paths[i].substr(0, index);
            index += 1;
            while (index < paths[i].size())
            {
                preIndex = index;
                //解析文件名
                while (paths[i][index] != '(')
                {
                    index += 1;
                }
                filename = paths[i].substr(preIndex, index - preIndex);

                index += 1;
                preIndex = index;
                //解析文件内容
                while (paths[i][index] != ')')
                {
                    index += 1;
                }
                content = paths[i].substr(preIndex, index - preIndex);
                if (!indexMap.count(content))
                {
                    indexMap[content] = ans.size();
                    ans.push_back(vector<string>());
                }
                ans[indexMap[content]].emplace_back(pre + "/" + filename);
                index += 2;
            }
        }
        for (vector<string>& file : ans)
        {
            if (file.size() > 1)
            {
                res.emplace_back(file);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> paths = {
        "root/a 1.txt(abcd) 2.txt(efgh)",
        "root/c 3.txt(abcd)",
        "root/c/d 4.txt(efgh)",
        "root 4.txt(efgh)"
    };
    s.findDuplicate(paths);
}