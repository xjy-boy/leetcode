#include<iostream>
#include<queue>

using namespace std;

class RecentCounter {
private:
    queue<int> pingQueue;
public:
    RecentCounter() {

    }

    int ping(int t) {
        pingQueue.push(t);
        while (true)
        {
            if (t-3000 <= pingQueue.front())
            {
                return pingQueue.size();
            }
            else
            {
                pingQueue.pop();
            }
        }
    }
};

int main()
{
    RecentCounter r = RecentCounter();
    cout << r.ping(1) << endl;
    cout << r.ping(100) << endl;
    cout << r.ping(3001) << endl;
    cout << r.ping(3002) << endl;
}