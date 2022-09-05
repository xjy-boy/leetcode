#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int result = 0;
        int sum = 0;
        vector<int> presum; //前缀和数组
        stack<int> index_stack;  //栈
      
        presum.push_back(0); //添加头部
        index_stack.push(0);

        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8) {
                sum += 1;
            }
            else {
                sum -= 1;
            }
            // 更新最长1类型时间段
            if (sum > 0) {
                result = i + 1;
            }
       
            //第一次出现，入栈
            if (sum < presum[index_stack.top()]) {
                index_stack.push(i+1);
            }
            
            //记录前缀和
            presum.push_back(sum);
        }
        
        // 从后向前遍历
        for (int i = presum.size() - 1; i > result; i--) {
            // 当前位置元素比栈顶元素大时，不断出栈
            while (presum[i] > presum[index_stack.top()] && !index_stack.empty()){
                result = max(result, i - index_stack.top());
                index_stack.pop();
            }

            if (index_stack.empty()) {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> hours = { 6,6,9 };
    cout << solution.longestWPI(hours) << endl;
}