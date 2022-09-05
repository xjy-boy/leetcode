#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
		string ans;

		vector<int> num = {308915776, 11881376,456976,17576,676,26,1 };
		vector<int> sum = { 321272406,12356630,475254,18278,702,26,0 };
		int start = 0;
		columnNumber -= 1;
		while (columnNumber < sum[start])
		{
			start += 1;
		}
		for (int i = start; i < 7; i++)
		{
			int n = (columnNumber - sum[i]) / num[i];
			ans += 'A' + n;
			columnNumber = columnNumber - num[i] * (n + 1);
		}
		return ans;
    }
};
int main()
{
	Solution s;
	for (int i = 0; i < 800; i++)
	{
		cout << s.convertToTitle(i+1) << endl;
	}
}