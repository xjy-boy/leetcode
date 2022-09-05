#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> table;
    int mod = 1 << 10;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        map.insert(1,1);
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return 0;
    }
};

int main()
{
    RandomizedSet set = RandomizedSet();
    set.getRandom();
}