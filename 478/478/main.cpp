#include<iostream>
#include<vector>
#include<random>
using namespace std;


class Solution {
private:
    double r;
    double x;
    double y;
    default_random_engine e;
    uniform_real_distribution<double> u1;
    uniform_real_distribution<double> u2;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
        double PI = acos(-1);
        u1 = uniform_real_distribution<double>(-PI, PI);
        u2 = uniform_real_distribution<double>(0, r*r);
    }

    vector<double> randPoint() {
        double angle = u1(e);
        double length = u2(e);
        length = sqrt(length);
        vector<double> ans;
        ans.emplace_back(x + cos(angle) * length);
        ans.emplace_back(y + sin(angle) * length);
        return ans;
    }
};

int main()
{
    Solution s(1,0,0);
    for (int i = 0; i < 10; i++)
    {
        vector<double> ans = s.randPoint();
        cout << ans[0] << "\t" << ans[1] << endl;
    }
}