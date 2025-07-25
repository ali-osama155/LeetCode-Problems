#include <vector> 
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;
//*********v1********/
/*
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<int> dis;
        for (const auto& innerVec : arrays) {
        //if (!innerVec.empty()) { 
            int lastElement = innerVec.back();
            int FirstElement = innerVec.front();
           //
            dis.push_back(lastElement);
            dis.push_back(FirstElement);


        //}
        }
        sort(dis.begin(), dis.end());
        int mxdis = dis[dis.size()-1] - dis[0];
        return mxdis; 
    
}
}*/
//////////////////////////////////v2//////////////

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minElement = arrays[0].front();
        int maxElement = arrays[0].back();
        int maxDistance = 0;

        for (size_t i = 1; i < arrays.size(); ++i) {
            int currentMin = arrays[i].front();
            int currentMax = arrays[i].back();

            maxDistance = max(maxDistance, max(abs(currentMax - minElement), abs(maxElement - currentMin)));

            minElement = min(minElement, currentMin);
            maxElement = max(maxElement, currentMax);
        }

        return maxDistance;
    }
};
int main(){
Solution tst;
vector<vector<int>> ts= {
       {1,2,3},{0,5},{1,2,3}
    };
cout<<tst.maxDistance(ts);

}