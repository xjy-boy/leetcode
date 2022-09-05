#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count = vector<int>(26, 0);
        for (char c : s)
        {
            count[c - 'a'] += 1;
        }
        /*
        * 0:zero  
        * 1:one
        * 2:two  
        * 3:three
        * 4;four
        * 5:five
        * 6:six
        * 7:seven
        * 8:eight
        * 9:nine
        */
        vector<int> ansCount = vector<int>(10, 0);
        /*
        * 只有0有z,只有2有w，只有4有u，只有6有x,只有8有g
        * 首先解析0,2,4,6,8
        */
        //解析0
        ansCount[0] = count['z' - 'a'];
        //修改count
        count['z' - 'a'] -= ansCount[0];
        count['e' - 'a'] -= ansCount[0];
        count['r' - 'a'] -= ansCount[0];
        count['o' - 'a'] -= ansCount[0];

        //解析2
        ansCount[2] = count['w' - 'a'];
        //修改count
        count['t' - 'a'] -= ansCount[2];
        count['w' - 'a'] -= ansCount[2];
        count['o' - 'a'] -= ansCount[2];
        

        //解析4
        ansCount[4] = count['u' - 'a'];
        //修改count
        count['f' - 'a'] -= ansCount[4];
        count['o' - 'a'] -= ansCount[4];
        count['u' - 'a'] -= ansCount[4];
        count['r' - 'a'] -= ansCount[4];

        //解析6
        ansCount[6] = count['x' - 'a'];
        //修改count
        count['s' - 'a'] -= ansCount[6];
        count['i' - 'a'] -= ansCount[6];
        count['x' - 'a'] -= ansCount[6];

        //解析8
        ansCount[8] = count['g' - 'a'];
        //修改count
        count['e' - 'a'] -= ansCount[8];
        count['i' - 'a'] -= ansCount[8];
        count['g' - 'a'] -= ansCount[8];
        count['h' - 'a'] -= ansCount[8];
        count['t' - 'a'] -= ansCount[8];

        /*
       * 1:one
       * 3:three
       * 5:five
       * 7:seven
       * 9:nine
       */
        //1:o，3:t，5:f,7:s
        //解析1
        ansCount[1] = count['o' - 'a'];
        //修改count
        count['o' - 'a'] -= ansCount[1];
        count['n' - 'a'] -= ansCount[1];
        count['e' - 'a'] -= ansCount[1];


        //解析3
        ansCount[3] = count['t' - 'a'];
        //修改count
        count['t' - 'a'] -= ansCount[3];
        count['h' - 'a'] -= ansCount[3];
        count['r' - 'a'] -= ansCount[3];
        count['e' - 'a'] -= 2 * ansCount[3];

        //解析5
        ansCount[5] = count['f' - 'a'];
        //修改count
        count['f' - 'a'] -= ansCount[5];
        count['i' - 'a'] -= ansCount[5];
        count['v' - 'a'] -= ansCount[5];
        count['e' - 'a'] -= ansCount[5];

        //解析7
        ansCount[7] = count['s' - 'a'];
        //修改count
        count['s' - 'a'] -= ansCount[7];
        count['e' - 'a'] -= 2*ansCount[7];
        count['v' - 'a'] -= ansCount[7];
        count['n' - 'a'] -= ansCount[7];

        //最后解析9
        ansCount[9] = count['i' - 'a'];
        string ans;
        for (int i = 0; i < 10; i++)
        {
            ans += string(ansCount[i], i + '0');
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "owoztneoezeror";
    cout << solution.originalDigits(s) << endl;
}