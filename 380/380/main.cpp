#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int> index;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (index.count(val))
        {
            return false;

        }
        else
        {
            index[val] = data.size();
            data.emplace_back(val);
            return true;
        }
    }

    bool remove(int val) {
        if (index.count(val))
        {
            int i = index[val];
            data[i] = data.back();
            index[data.back()] = i;
            index.erase(val);
            data.pop_back();
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom() {
        return data[rand()%data.size()];
    }
};