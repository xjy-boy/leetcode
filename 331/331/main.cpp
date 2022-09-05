#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<int> grammarStack;
        // tree -> #
        // tree -> num tree tree
        // 1表示 num，0表示tree
        int index = 0;
        while (index < preorder.size())
        {
            if (preorder[index] == '#')
            {
                //对栈进行规约
                grammarStack.emplace_back(0);
                while (grammarStack.size() >= 3)
                {
                    if (grammarStack[grammarStack.size() - 1] == 0
                        && grammarStack[grammarStack.size() - 2] == 0
                        && grammarStack[grammarStack.size() - 3] == 1
                        )
                    {
                        grammarStack[grammarStack.size() - 3] = 0;
                        grammarStack.pop_back();
                        grammarStack.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                grammarStack.emplace_back(1);
            }

            //移动index
            while (index < preorder.size() && preorder[index] != ',')
            {
                index += 1;
            }
            index += 1;
        }

        return grammarStack.size() == 1 && grammarStack[0] == 0;
    }
};

int main()
{
    Solution solution;
    string s = "9,3,4,#,1,1,#,#,2,#,6,#,#";
    cout << solution.isValidSerialization(s) << endl;
}