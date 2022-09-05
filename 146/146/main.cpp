#include<iostream>
#include<unordered_map>

using namespace std;


struct MyNode
{
    int key;
    int value;
    MyNode* pre = NULL;
    MyNode* next = NULL;
    MyNode(int _key,int _value)
    {
        key = _key;
        value = _value;
        pre = NULL;
        next = NULL;
    }

    MyNode(int _key,int _value,MyNode *_pre,MyNode *_next)
    {
        key = _key;
        value = _value;
        pre = _pre;
        next = _next;
    }
};

class LRUCache {
private:
    unordered_map<int,MyNode*> nodeMap;
    int maxSize;
    int nowSize;
    MyNode* head;
    MyNode* end;
public:
    LRUCache(int capacity) {
        maxSize = capacity;
        nowSize = 0;
        head = new MyNode(0,0);
        end = new MyNode(0, 0);
        head->next = end;
        end->pre = head;
    }

    int get(int key) {
        if (nodeMap.count(key))
        {
            MyNode* p = nodeMap[key];
            if (p->pre != head)
            {
                MyNode* headNext = head->next;
                p->pre->next = p->next;
                p->next->pre = p->pre;
                p->next = headNext;
                headNext->pre = p;
                p->pre = head;
                head->next = p;
            }

            return p->value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        if (nodeMap.count(key))
        {
            nodeMap[key]->value = value;
            get(key);
        }
        else
        {
            if (nowSize == maxSize)
            {
                MyNode* last = end->pre;
                last->pre->next = end;
                end->pre = last->pre;
                nodeMap.erase(last->key);
                delete last;
            }
            else
            {
                nowSize += 1;
            }
            MyNode* p = new MyNode(key, value, head, head->next);
            head->next->pre = p;
            head->next = p;
            nodeMap[key] = p;
        }
    }
};

int main()
{
    LRUCache lRUCache(2);

    
    lRUCache.put(2, 1);
    lRUCache.put(1, 1); 
    lRUCache.put(2, 3);
    lRUCache.put(4, 1);
    cout << lRUCache.get(1) << endl;    
    cout << lRUCache.get(2) << endl;    
    

    /*
    cout << lRUCache.get(2) << endl;
    lRUCache.put(2, 6);
    cout << lRUCache.get(1) << endl;
    lRUCache.put(1, 5);
    lRUCache.put(1, 2);
    cout << lRUCache.get(1) << endl;
    cout << lRUCache.get(2) << endl;
    */
}