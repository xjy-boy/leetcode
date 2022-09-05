#include<vector>
#include<stack>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int result = 0;
        int sum = 0;
        vector<int> presum; //ǰ׺������
        stack<int> index_stack;  //ջ
      
        presum.push_back(0); //���ͷ��
        index_stack.push(0);

        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] > 8) {
                sum += 1;
            }
            else {
                sum -= 1;
            }
            // �����1����ʱ���
            if (sum > 0) {
                result = i + 1;
            }
       
            //��һ�γ��֣���ջ
            if (sum < presum[index_stack.top()]) {
                index_stack.push(i+1);
            }
            
            //��¼ǰ׺��
            presum.push_back(sum);
        }
        
        // �Ӻ���ǰ����
        for (int i = presum.size() - 1; i > result; i--) {
            // ��ǰλ��Ԫ�ر�ջ��Ԫ�ش�ʱ�����ϳ�ջ
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