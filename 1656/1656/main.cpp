#include<iostream>
#include<vector>

using namespace std;


class OrderedStream {
public:
    vector<string> data;
    int ptr = 0;
    OrderedStream(int n) {
        data = vector<string>(n, "");
        ptr = 0;
    }

    vector<string> insert(int idKey, string value) {
        idKey -= 1;
        data[idKey] = value;
        vector<string> ans;
        while (ptr < data.size() && !data[ptr].empty())
        {
            ans.emplace_back(data[ptr]);
            ptr += 1;
        }
        return ans;
    }
};

int main()
{
    OrderedStream o(5);
    o.insert(3, "ccccc");
    o.insert(1, "aaaaa");
    o.insert(2, "bbbbb");
    o.insert(5, "eeeee");
    o.insert(4, "ddddd");
}