#include<iostream>
#include<unordered_set>

using namespace std;


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_set<int> begins;
        int index1 = 0;
        int index2 = 0;
        int ans = 0;

        while (index1 < s1.size() && s1[index1] != s2[0])
        {
            index1 += 1;
        }

        if (index1 == s1.size())
        {
            return 0;
        }
        int begin = index1;
        int k1 = 0;
        int k2 = 0;

        int t1 = 0;
        int pre = 0;

        vector<int> f1 = vector<int>(s1.size(), -1);
        vector<int> f2 = vector<int>(s1.size(), -1);

        while (f1[index1] < 0)
        {
            pre = index1;
            index2 = 0;
            //匹配s2
            t1 = 0;
            while (index2 < s2.size())
            {
                if (s1[index1] == s2[index2])
                {
                    index2 += 1;
                }
                index1 += 1;
                if (index1 >= s1.size())
                {
                    t1 += 1;
                    k1 += 1;
                    index1 = 0;
                }
            }
            k2 += 1;
            //寻找下个开头
            while (s1[index1] != s2[0])
            {
                index1 += 1;
                //正好分配
                if (index1 >= s1.size())
                {
                    k1 += 1;
                    index1 = 0;
                    break;
                }
            }
            if (index1 == 0)
            {
                ans = n1 / k1 * k2;
                n1 = n1 % k1;
                index1 = 0;
                while (n1 > 0 && f1[index1] >= 0)
                {
                    n1 -= f1[index1];
                    index1 = f2[index1];
                    if (n1 > 0)
                    {
                        ans += 1;
                    }
                }
                return ans / n2;
            }
            else
            {
                f1[pre] = t1;
                f2[pre] = index1;
            }
        }
        //寻找循环
        int lootK1 = f1[index1];
        int lootK2 = 1;
        int lootBegin = index1;
        index1 = f2[index1];
        while (index1 != lootBegin)
        {
            lootK1 += f1[index1];
            lootK2 += 1;
            index1 = f2[index1];
        }
        int last = (n1 - 1) % lootK1 + 1;
        ans = (n1 - 1) / lootK1 * lootK2;

        //首先第一行，lootBegin之前
        index1 = begin;
        while (f1[index1] == 0 && index1 < lootBegin)
        {
            ans += 1;
            index1 = f2[index1];
        }

        //循环后剩余的部分
        if (n1 == last)
        {
            index1 = 0;
            index2 = 0;
        }
        else
        {
            index1 = lootBegin;
            index2 = 0;
        }
        while (last > 0)
        {
            if (s1[index1] == s2[index2])
            {
                index2 += 1;
            }
            index1 += 1;
            if (index1 >= s1.size())
            {
                index1 = 0;
                last -= 1;
            }
            if (index2 >= s2.size())
            {
                index2 = 0;
                ans += 1;
            }
        }

        return ans / n2;
    }   
};

int main()
{
    Solution s;
    //string s1 = "baba";
    //string s2 = "baab";
    string s1 = "nlhqgllunmelayl";
    string s2 = "lnl";
    cout << s.getMaxRepetitions(s1, 2, s2, 1) << endl;
}