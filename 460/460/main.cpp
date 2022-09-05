#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

struct MyNode {
    int key = 0;
    int value = 0;
    int fre = 0;
    MyNode(int _key, int _value,int _fre)
    {
        key = _key;
        value = _value;
        fre = _fre;
    }
};

class LFUCache {
public:
    unordered_map<int, list<MyNode>::iterator> cache;
    unordered_map<int, list<MyNode>> frequencyMap;
    int c = 0;
    int minF = 0;
    LFUCache(int capacity) {
        c = capacity;
        minF = 0;
        cache.clear();
        frequencyMap.clear();
    }

    int get(int key) {
        if (c == 0)
        {
            return -1;
        }
        if (cache.count(key))
        {
            auto node = cache[key];
            int key = node->key;
            int value = node->value;
            int fre = node->fre;

            //更新
            frequencyMap[fre].erase(node);
            if (frequencyMap[fre].empty())
            {
                frequencyMap.erase(fre);
                if (minF == fre)
                {
                    minF += 1;
                }
            }

            fre += 1;
            frequencyMap[fre].emplace_front(key, value, fre);
            cache[key] = frequencyMap[fre].begin();
            return value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        if (c == 0)
        {
            return;
        }
        //若key已经存在
        else if (cache.count(key))
        {
            auto node = cache[key];
            int fre = node->fre;
            //更新
            frequencyMap[fre].erase(node);
            if (frequencyMap[fre].empty())
            {
                frequencyMap.erase(fre);
                if (minF == fre)
                {
                    minF += 1;
                }
            }
            fre += 1;
            frequencyMap[fre].emplace_front(key, value, fre);
            cache[key] = frequencyMap[fre].begin();
        }
        //key不存在
        else
        {
            //缓存已满，进行删除
            if (cache.size() == c)
            {
                cache.erase(frequencyMap[minF].back().key);
                frequencyMap[minF].pop_back();
                if (frequencyMap[minF].empty())
                {
                    frequencyMap.erase(minF);
                }
            }
            //进行插入
            frequencyMap[1].emplace_front(key, value, 1);
            cache[key] = frequencyMap[1].begin();
            minF = 1;
        }
    }
};

int main()
{
    LFUCache l(10);
    
    l.put(10, 13);
    l.put(3, 17);
    l.put(6, 11);
    l.put(10, 5);
    l.put(9, 10);

    cout << l.get(13) << endl;
    l.put(2, 19);

    cout << l.get(2) << endl;
    cout << l.get(3) << endl;

    l.put(5, 25);
    cout << l.get(8) << endl;

    l.put(9, 22);
    l.put(5, 5);
    l.put(1, 30);

    cout << l.get(11) << endl;
    l.put(9, 12);

    cout << l.get(7) << endl;
    cout << l.get(5) << endl;
    cout << l.get(8) << endl;
    cout << l.get(9) << endl;

    l.put(4, 30);
    l.put(9,3);

    cout << l.get(9) << endl;
    cout << l.get(10) << endl;
    cout << l.get(10) << endl;

    l.put(6, 14);
    l.put(3, 1);

    cout << l.get(3) << endl;
    l.put(10, 11);

    cout << l.get(8) << endl;
    l.put(2, 14);

    cout << l.get(1) << endl;
    cout << l.get(5) << endl;
    cout << l.get(4) << endl;

    l.put(11, 4);
    l.put(12, 24);
    l.put(5, 18);

    cout << l.get(13) << endl;
    l.put(7, 23);

    cout << l.get(8) << endl;
    cout << l.get(12) << endl;

    l.put(3, 27);
    l.put(2, 12);

    cout << l.get(5) << endl;
    l.put(2, 9);
    l.put(13, 4);
    l.put(8, 18);
}
