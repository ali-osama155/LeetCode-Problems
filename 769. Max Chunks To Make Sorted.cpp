#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = 0;
        int chunks = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) { 
                chunks++;
            }
        }
        
        return chunks;
    }
};
int main (){
    Solution sol;
    vector<int> arr = {1,2,0,3};
    cout<<sol.maxChunksToSorted(arr)<<endl;
}