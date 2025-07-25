#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> result(n + 1); 
        std::iota(result.begin(), result.end(), 0);
        result.erase(std::remove_if(result.begin(), result.end(),
        [&banned](int x) {
            return std::find(banned.begin(), banned.end(), x) != banned.end();}),
        result.end());
        int counter = 0;
        int sum = 0;
        for(int i = 0; i<result.size() ;i++){
            sum += result[i];
            if(sum>maxSum) break;
            else counter++;
        }
        
    return counter; }
};