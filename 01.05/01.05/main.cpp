#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.size() == second.size())
        {
            return changeEdit(first, second);
        }
        else if (first.size() == second.size() + 1)
        {
            return delEdit(first, second);
        }
        else if (first.size() == second.size() - 1)
        {
            return delEdit(second, first);
        }
        else
        {
            return false;
        }
    }

    bool changeEdit(string first, string second) {
        bool change = false;
        for (int i = 0; i < first.size(); i++)
        {
            if (first[i] != second[i])
            {
                if (change)
                {
                    return false;
                }
                change = true;
            }
        }
        return true;
    }

    bool delEdit(string first, string second) {
        bool change = false;
        int index1 = 0;
        int index2 = 0;
        while (index1 < first.size())
        {
            if (first[index1] != second[index2])
            {
                if (change)
                {
                    return false;
                }
                change = true;
                index1 += 1;
                continue;
            }
            index1 += 1;
            index2 += 1;
            
        }
        return true;
    }
};