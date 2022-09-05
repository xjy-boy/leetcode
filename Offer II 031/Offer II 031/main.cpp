#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class LRUCache {
    struct Data
    {
        int key;
        int value;
        Data(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };
private:
    vector<Data>data;
    int maxCapacity;
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
    }

    int get(int key) {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i].key == key)
            {
                int value = data[i].value;
                data.push_back(data[i]);
                data.erase(data.begin() + i);
                return value;
            }
        }
        return -1;
    }

    void put(int key, int value) {
        if (data.size() == maxCapacity)
        {
            data.erase(data.begin());
        }
        data.push_back(Data(key, value));
    }
};


int main()
{
    LRUCache cache = LRUCache(5);
    cache.put(1, 0);
    cache.put(1, 0);
    cache.put(1, 0);
    cache.put(1, 0);
    cache.put(1, 0);
}