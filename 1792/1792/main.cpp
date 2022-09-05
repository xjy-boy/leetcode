#include<queue>
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		struct MyStruct
		{
			int total;
			int pass;
			double compare;
			bool operator < (const MyStruct& a) const
			{
				return compare < a.compare;
			}

			bool operator > (const MyStruct& a) const
			{
				return compare > a.compare;
			}
		};

		priority_queue<MyStruct> q;
		for(int i = 0; i < classes.size(); i++){
			MyStruct myStruct;
			myStruct.pass = classes[i][0];
			myStruct.total = classes[i][1];
			myStruct.compare = (double)(myStruct.total - myStruct.pass) / myStruct.total / (myStruct.total + 1);
			q.push(myStruct);
		}
		for (int i = 0; i < extraStudents; i++) {
			MyStruct myStruct = q.top();
			myStruct.pass += 1;
			myStruct.total += 1;
			myStruct.compare = (double)(myStruct.total - myStruct.pass) / myStruct.total / (myStruct.total + 1);
			q.pop();
			q.push(myStruct);
		}
		double result = 0;
		while (!q.empty()){
			MyStruct myStruct = q.top();
			result += (double)myStruct.pass / myStruct.total;
			q.pop();
		}
		return result / classes.size();
    }
};

int main() {
	vector<vector<int>> classes = { {1,2},{3,5},{2,2}};
	int extraStudents = 2;
	Solution solution = Solution();
	cout << solution.maxAverageRatio(classes, extraStudents) << endl;
}