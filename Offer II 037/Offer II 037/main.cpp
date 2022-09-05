#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> asStack;
        
        for (int asteroid : asteroids)
        {
            //�����ƶ���
            if (asteroid > 0)
            {
                asStack.push(asteroid);
            }
            //�����ƶ���
            else
            {
                if (asStack.empty())
                {
                    result.push_back(asteroid);
                }
                else
                {
                    while (true)
                    {
                        if (-asteroid > asStack.top())
                        {
                            asStack.pop();
                            if (asStack.empty())
                            {
                                result.push_back(asteroid);
                                break;
                            }
                        }
                        else if (-asteroid == asStack.top())
                        {
                            asStack.pop();
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        vector<int> temple;
        while (!asStack.empty())
        {
            temple.push_back(asStack.top());
            asStack.pop();
        }
        result.insert(result.end(), temple.rbegin(), temple.rend());
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    vector<int> asteroids = {-2,-1,1,2 };
    solution.asteroidCollision(asteroids);
}