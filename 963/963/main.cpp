#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<int, vector<vector<int>>> pointsMap;
        vector<vector<int>> lengthMatrix;
        
        int pointsNumber = points.size();
        for (int i = 0; i < pointsNumber; i++) {
            lengthMatrix.push_back(vector<int>(pointsNumber, 0));
        }
        for (int i = 0; i < pointsNumber; i++) {
            for (int j = i + 1; j < pointsNumber; j++) {
                long int length = pow((points[i][0] - points[j][0]),2)
                    + pow((points[i][1] - points[j][1]), 2);
                lengthMatrix[i][j] = length;
                lengthMatrix[j][i] = length;

                //插入哈希表
                if (pointsMap.count(length)) {
                    pointsMap[length].push_back({ i,j });
                }
                else{
                    pointsMap[length] = { {i,j} };
                }
            }
        }
        double result = -1;
        for (auto it = pointsMap.begin(); it != pointsMap.end(); it++) {
            if (it->second.size() == 1) {
                continue;
            }
            else {
                for (int i = 0; i < it->second.size(); i++) {
                    for (int j = i + 1; j < it->second.size(); j++) {
                        //若有相同的点
                        if (it->second[i][0] == it->second[j][0] || it->second[i][0] == it->second[j][1]
                            || it->second[i][1] == it->second[j][0] || it->second[i][1] == it->second[j][1]) {
                            continue;
                        }

                        // 判断是否是矩形
                        int x1 = points[it->second[i][0]][0];
                        int y1 = points[it->second[i][0]][1];
                        int x2 = points[it->second[i][1]][0];
                        int y2 = points[it->second[i][1]][1];
                        int x3 = points[it->second[j][0]][0];
                        int y3 = points[it->second[j][0]][1];
                        int x4 = points[it->second[j][1]][0];
                        int y4 = points[it->second[j][1]][1];
                        double s = -1;

                        //判断是否是矩形
                        if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0 &&
                            (x1 - x2) * (x4 - x2) + (y1 - y2) * (y4 - y2) == 0) {
                            //计算面积
                            s = (double)it->first * lengthMatrix[it->second[i][0]][it->second[j][0]];                            
                        }
                        else if ((x2 - x1) * (x4 - x1) + (y2 - y1) * (y4 - y1) == 0 &&
                               (x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0) {
                            //计算面积
                            s = (double)it->first * lengthMatrix[it->second[i][0]][it->second[j][1]];
                        }
                        else{
                            // 不是矩形
                            continue;
                        }
                        
                        if (s < result || result == -1) {
                            result = s;
                        }
                    }
                }
            }
        }
        if (result == -1) {
            return 0;
        }
        else {
            return sqrt(result);
        }
    }
};

int main() {
    vector<vector<int>> points = {
        {{24420,16685},{20235,25520},{14540,20845},{20525,14500},{16876,24557},{24085,23720},{25427,18964},{21036,14573},{24420,23315},{22805,24760},{21547,25304},{16139,23952},{21360,14645},{24715,17120},{19765,25520},{19388,25491},{22340,25005},{25520,19765},{25365,21320},{23124,15443},{20845,14540},{24301,16532},{16685,24420},{25100,17875},{22125,25100},{15699,23468},{14592,21131},{25460,19155},{17837,25084},{23468,24301},{25460,20845},{18453,25304},{21131,14592},{22805,15240},{19475,25500},{15443,23124},{25355,21360},{15285,22880},{20000,25525},{24085,16280},{22163,25084},{22880,15285},{14916,22163},{16280,24085},{24875,17400},{22600,24875},{14573,21036},{25427,21036},{17120,24715},{25500,19475} }
};
    Solution solution = Solution();
    cout << solution.minAreaFreeRect(points) << endl;
}