#include<iostream>
#include<stack>
#include<deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> pathStack;
        int index = 0;
        while (index < path.size())
        {
            while (index < path.size() && path[index] == '/')
            {
                index += 1;
            }
            string dir = "";
            while (index < path.size() && path[index] != '/')
            {
                dir += path[index];
                index += 1;
            }
            if (dir == ".")
            {
                continue;
            }
            else if (dir == "..")
            {
                if (!pathStack.empty())
                {
                    pathStack.pop_back();
                }
            }
            else if(dir != "")
            {
                pathStack.push_back(dir);
            }
        }
        string ans = "/";
        while (!pathStack.empty())
        {
            ans += pathStack.front();
            ans += "/";
            pathStack.pop_front();
        }
        if (ans != "/")
        {
            ans.pop_back();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string path = "/../";
    cout << s.simplifyPath(path) << endl;
}