#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //一次遍历
        int right = 0;
        int left = 0;
        int ans = 0;
        int kF = k;
        int kT = k;
        while (right < answerKey.size())
        {
            if (answerKey[right] == 'F')
            {
                kT -= 1;
                //若对F可以移动
                if (kF >= 0)
                {
                    ans += 1;
                }
                else
                {
                    //对T可以移动
                    if (kT >= 0)
                    {
                        ans += 1;
                    }
                    //需要移动左端
                    else
                    {
                        if (answerKey[left] == 'T')
                        {
                            kF += 1;
                        }
                        else
                        {
                            kT += 1;
                        }
                        left += 1;
                    }
                }
            }
            else
            {
                kF -= 1;
                //若对T可以移动
                if (kT >= 0)
                {
                    ans += 1;
                }
                else
                {
                    //对F可以移动
                    if (kF >= 0)
                    {
                        ans += 1;
                    }
                    //需要移动左端
                    else
                    {
                        if (answerKey[left] == 'T')
                        {
                            kF += 1;
                        }
                        else
                        {
                            kT += 1;
                        }
                        left += 1;
                    }
                }
            }
            right += 1;
        }
        return ans;
    }

    //两次遍历
    int maxConsecutiveAnswers(string &answerKey, int k, char c)
    {
        int right = 0;
        int left = 0;
        int ans = 0;
        
        while (right < answerKey.size())
        {
            //只移动右端
            if (answerKey[right] == c && k >= 0)
            {
                ans += 1;
            }
            //同时移动左端，并修改k值
            else if(answerKey[right] == c && k < 0)
            {
                if (answerKey[left] != c)
                {
                    k += 1;
                }
                left += 1;
            }
            //只移动右端，修改k值
            else if (answerKey[right] != c && k > 0)
            {
                ans += 1;
                k -= 1;
            }
            //同时移动左端，并修改k值
            else
            {
                k -= 1;
                if (answerKey[left] != c)
                {
                    k += 1;
                }
                left += 1;
            }

            right += 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.maxConsecutiveAnswers("TTTFTFFTFFFTTTTFTTFTTTFTFFFFFTFFFTFFTFFTFTFFFTTTTFTTTFFFFFTTFFTFFTFFFFTFTFFFTFFFTFTTFTTFTFTTFFFTFFFF"
        ,18) << endl;
}