#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int count = 0;
        for (int i = 1; i < heightMap.size()-1; i++) {
            for(int j = 1; j < heightMap[i].size()-1; j++) {
                auto max = max_element(heightMap[i].begin()+1, heightMap[i].end()-1);
                count += *max - heightMap[i][j];
            }
        }   
    }
};