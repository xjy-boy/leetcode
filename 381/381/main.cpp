#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<random>

using namespace std;


class RandomizedCollection {
public:
    vector<int> data;
    unordered_map<int, unordered_set<int>> indexMap;
    RandomizedCollection() {

    }

    bool insert(int val) {
        if (indexMap.count(val) && !indexMap[val].empty())
        {
            indexMap[val].insert(data.size());
            data.emplace_back(val);
            return false;
        }
        else 
        {
            if (!indexMap.count(val))
            {
                indexMap[val] = unordered_set<int>();
            }
            indexMap[val].insert(data.size());
            data.emplace_back(val);
            return true;
        }
    }

    bool remove(int val) {
        if (!indexMap.count(val)
            || indexMap[val].empty())
        {
            return false;
        }
        else
        {
            int nextVal = data.back();
            if (nextVal == val)
            {
                data.pop_back();
                indexMap[nextVal].erase(data.size());
            }
            else
            {
                int index = *indexMap[val].begin();
                data[index] = nextVal;
                data.pop_back();
                indexMap[val].erase(index);
                indexMap[nextVal].erase(data.size());
                indexMap[nextVal].insert(index);
            }
            return true;
        }
    }

    int getRandom() {
        return data[rand() % data.size()];
    }
};

int main()
{
    RandomizedCollection r;
    r.insert(1);
    r.remove(0);
    r.insert(2);
    r.remove(1);
    r.getRandom();
}