#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        //һ�α���
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
                //����F�����ƶ�
                if (kF >= 0)
                {
                    ans += 1;
                }
                else
                {
                    //��T�����ƶ�
                    if (kT >= 0)
                    {
                        ans += 1;
                    }
                    //��Ҫ�ƶ����
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
                //����T�����ƶ�
                if (kT >= 0)
                {
                    ans += 1;
                }
                else
                {
                    //��F�����ƶ�
                    if (kF >= 0)
                    {
                        ans += 1;
                    }
                    //��Ҫ�ƶ����
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

    //���α���
    int maxConsecutiveAnswers(string &answerKey, int k, char c)
    {
        int right = 0;
        int left = 0;
        int ans = 0;
        
        while (right < answerKey.size())
        {
            //ֻ�ƶ��Ҷ�
            if (answerKey[right] == c && k >= 0)
            {
                ans += 1;
            }
            //ͬʱ�ƶ���ˣ����޸�kֵ
            else if(answerKey[right] == c && k < 0)
            {
                if (answerKey[left] != c)
                {
                    k += 1;
                }
                left += 1;
            }
            //ֻ�ƶ��Ҷˣ��޸�kֵ
            else if (answerKey[right] != c && k > 0)
            {
                ans += 1;
                k -= 1;
            }
            //ͬʱ�ƶ���ˣ����޸�kֵ
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